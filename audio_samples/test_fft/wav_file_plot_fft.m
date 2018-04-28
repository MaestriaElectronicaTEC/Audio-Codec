% Test: veryfing the functionality of reading wav files
% Objective: plot a wav file
% Results: functional script

[audio,fs] = audioread('music_test_0.wav');
audio = audio(:,1);

L = length(audio);
f = fs*(0:(L/2))/L;
t = (0:L-1)*(1/fs);        % Time vector

Y1 = fft(audio);
P1 = abs(Y1/L);
P1 = P1(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

% Plot the signal
subplot(2,1,1);
plot(t,audio)
title('WAV Audio signal')
xlabel('t [milliseconds]')
ylabel('audio (t)')
subplot(2,1,2);
plot(f,P1) 
title('Audio signal FFT')
xlabel('f [Hz]')
ylabel('|P1(f)|')
