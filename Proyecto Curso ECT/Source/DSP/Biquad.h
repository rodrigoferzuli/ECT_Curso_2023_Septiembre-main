/*
  ==============================================================================

    Biquad.h
    Created: 14 Oct 2023 12:53:07am
    Author:  Drogui

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class LPF_Biquad {
 public:
  LPF_Biquad();
  ~LPF_Biquad();

  void prepare(double inSampleRate);

  void process(juce::AudioBuffer<float>& inBuffer);
  float processSample(float inSample, int channel);

  void setFrequency(float inFrequency);
  void setQ(float inQ);

 private:
  void updateFilter();

  double sampleRate{0.0f};

  float x1[2] = {0.0f};
  float x2[2] = {0.0f};
  float y1[2] = {0.0f};
  float y2[2] = {0.0f};

  float w0{0.0f};
  float alpha{0.0f};

  float b0{0.0f};
  float b1{0.0f};
  float b2{0.0f};
  float a0{0.0f};
  float a1{0.0f};
  float a2{0.0f};

  float frequency{1000.0f};
  float Q{0.71f};
};
