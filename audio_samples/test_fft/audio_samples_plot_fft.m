% Name: Fabricio Quiros Corella
% Description: FFT proof-of-concept, test audio samples generated
% Date: 04/15/2018

% Definitios
int64 data1; % audio data samples
int64 data2;

% Retreiving the sample data from the audio file (Tone)
data1 = csvread('sample-data_tone_test_1.2.csv'); % 1 block of samples
data2 = csvread('sample-data_tone_test_1.3.csv'); % 2 block of samples

% Time domain plot settings - 1 samples blocks
sample_value_1 = data1(:,1);
time_ms_1 = data1(:,2);
figure 1;
plot(time_ms_1, sample_value_1);
title('Time domain plot - Audio sample tone - 1 samples block');
xlabel('Time [ms]');
ylabel("Amplitude");

% Time domain plot settings - 1 samples blocks
sample_value_2 = data2(:,1);
time_ms_2 = data2(:,2);
figure 2;
plot(time_ms_2, sample_value_2);
axis([0, 16]);
title('Time domain plot - Audio sample tone - 2 samples block');
xlabel('Time [ms]');
ylabel("Amplitude");