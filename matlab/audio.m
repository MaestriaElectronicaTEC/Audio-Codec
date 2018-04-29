% Read data from WAV audio file 
[X1,Fs] = audioread('music_test_0.wav');
audiofile = 'reconstructed_audio.wav';
filename = 'byte_pack';
X1 = X1(:,1)';

% Map
function bytePack = map(X)
  bytePack = [];
  % Original number of bits
  BitsI = length(X)*128; % 1 Complex = 128 bits
  for base = 1 : 63 : length(X)-64
    Y = fft(X(base:base+63));
    rY = [Y(1) real(Y(2:32))];
    iY = [Y(33) imag(Y(2:32))];
    o = single(abs(min([rY iY])));    %offset
    q = single(max([rY iY].+o)/256);  %quantum
    rY = uint8((rY.+abs(o))./q);
    iY = uint8((iY.+abs(o))./q);
    %save o and q using 8.8 fixed point
    q = double(q*256);
    o = double(o*256);
    qu = uint8(floor(q/256));
    ql = uint8(mod(q,256));
    ou = uint8(floor(o/256));
    ol = uint8(mod(o,256));
    bytePack = [bytePack rY iY qu ql ou ol];
  endfor
  % Final number of bits
  BitsF = length(bytePack)*8;
  Compression = [num2str(100*(BitsI-BitsF)/BitsI) "%"]
endfunction

function X = unmap(bytePack)
  X = [];
  for base = 1 : 68 : length(bytePack)
    rY = bytePack(base:base+31);
    iY = bytePack(base+32:base+63);
    qu = bytePack(base+64);
    ql = bytePack(base+65);
    ou = bytePack(base+66);
    ol = bytePack(base+67);
    q = double(qu)+double(ql)/256;
    o = double(ou)+double(ol)/256;
    rY = double(rY).*q.-o;
    iY = double(iY).*q.-o;
    Y = rY(2:end) + i*iY(2:end);
    Y = [rY(1) Y iY(1) fliplr(conj(Y))];
    %IFFT
    X1 = real(ifft(Y));
    if length(X)==0
      X = X1; 
    else
      X = [X(1:end-1) (X(end)+X1(1))/2 X1(2:end)];
    endif
  endfor
  Y = fft(X);
  x = 0:1:length(Y)-1;
  g = 2.*e.^((-(x).^2)./(2*(length(Y)/8)**2));
  X = real(ifft(Y.*g));
endfunction

function plotWavesFft(X1, X2, Fs)
  L = length(X1);
  f = Fs*(0:(L/2))/L;
  t = (0:L-1)*(1/Fs);

  Y1 = fft(X1);
  P1 = abs(Y1/L);
  P1 = P1(1:L/2+1);
  P1(2:end-1) = 2*P1(2:end-1);
  Y2 = fft(X2);
  P2 = abs(Y2/L);
  P2 = P2(1:L/2+1);
  P2(2:end-1) = 2*P2(2:end-1);

  figure(1);
  % Plot the signal
  subplot (2, 2, 1)
  plot(1000*t,X1)
  title('Original signal')
  xlabel('t (milliseconds)')
  ylabel('X1(t)')
  subplot (2, 2, 2)
  plot(f,P1) 
  title('Original FFT')
  xlabel('f (Hz)')
  ylabel('|P1(f)|')

  % Plot the result
  subplot (2, 2, 3)
  plot(1000*t,X2)
  title('Reconstructed signal')
  xlabel('t (milliseconds)')
  ylabel('X2(t)')
  subplot (2, 2, 4)
  plot(f,P2) 
  title('Reconstructed FFT')
  xlabel('f (Hz)')
  ylabel('|P1(f)|')
endfunction

Pack = map(X1);

% write and read binary
fid = fopen( filename, 'w' );
fwrite( fid, Pack, 'uint8' );
fclose( fid );
fid = fopen( filename, 'r' );
Pack = fread( fid, size(Pack), 'uint8' );
fclose( fid );

X2 = unmap(Pack);
X1 = X1(1:length(X2));
audiowrite(audiofile,X2,Fs);
Error = [num2str(100*norm(X1-X2)/norm(X1)) "%"]
plotWavesFft(X1, X2, Fs);
