/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors


 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 copied UDT 1:
 */
#include <iostream>

struct Adsr       
{
    int attack = 127;
    int decay = 127;
    int sustain = 23;
    int release = 27; 
    float amount = 127.0;

    ~Adsr(){
        std::cout << "Destructed Adsr"<< std::endl;
    } //destructor

    int changeAttack(int knobValue)
    {
        attack = knobValue * int(amount)/100;
        return attack;
    }

    int changeDecay(int knobValue)
    {
        decay = knobValue * int(amount)*23;
        return decay;
    }

    int changeRelease(int knobValue)
    {
        release = knobValue/123*100;
        return release;
    }
};

/*
 copied UDT 2:
 */

struct Midi       
{
    int value = 127;
    int channel = 127; 
    int input = 127;
    int output = 127;
    bool syncType = true; 

    ~Midi(){
        std::cout << "Destructed Midi"<< std::endl;
    } //destructor


    struct MidiMessage   
    {
        bool isEnabled = false;

        void sendSignal(int midiMessage); 
        void getSignal(); 
    };


    void sendMidi(MidiMessage midiMessage)
    {
        if(midiMessage.isEnabled)
        {
            midiMessage.sendSignal(value);
        }
    }
    void receiveMidi(MidiMessage midiMessage)
    {
        if(midiMessage.isEnabled)
        {
            midiMessage.getSignal();
        }
    }
    void enableMidi(bool enableMidi, MidiMessage midiMessage)
    {
        if(enableMidi)
        {
            midiMessage.isEnabled = true;
        }
    }

};
/*
 copied UDT 3:
 */
struct Oscillator       
{
    int volume = 127; 
    double sin = 127.0; 
    double square = 23.0; 
    double triangle = 27.0; 
    float noise = 127.0f;

    ~Oscillator(){
        std::cout << "Destructed Oscillator"<< std::endl;
    } //destructor

    double waveform(int waveform)
    {   
        double modulatedWaveform = 0;
        
        if(waveform == 1)
        {
            modulatedWaveform = sin * 345;
        }
        else if(waveform == 2)
        {
            modulatedWaveform = square * 333;
        }
        else if(waveform == 3)
        {
            modulatedWaveform = triangle * 360;
        }
        return modulatedWaveform;
    }
    bool sounds(bool oscillatorOn)
    {
        if(oscillatorOn && sin >= 30)
        {
            oscillatorOn = true;
        }
        else
        {
            oscillatorOn = false;
        }
        return oscillatorOn;
    }
    int changeVolume();
};

/*
 new UDT 4:
 */

struct Synthesizer       
{
    Oscillator oscillator;
    Adsr adsr;
    Midi midi;
    
    ~Synthesizer(){
        std::cout << "Destructed Synthesizer: " << adsr.changeAttack(12) << std::endl;
    } //de

    void createSounds(Oscillator oscillatorSynth, int waveform)
    {
        oscillatorSynth.waveform(waveform);
    }
    void sendMidi(Midi midiSynth, Midi::MidiMessage midiMessage)
    {
        midiSynth.sendMidi(midiMessage);
    }
    void manipulateSoundAdsr(Adsr adsrSynth, int parameter, int knobValue)
    { 
        if(parameter == 0)
        {
            adsrSynth.changeAttack(knobValue);
        }
        else if(parameter == 1)
        {
            adsrSynth.changeDecay(knobValue);
        }
        else if(parameter == 2)
        {
            adsrSynth.changeRelease(knobValue);
        }    
    }
    
};

struct Sampler       
{
    Adsr adsr; 
    Midi midi; 

    ~Sampler(){
        std::cout << "Destructed Sampler: " << adsr.changeRelease(3) << std::endl;
    } //de
    void changeSampleAdsr(Adsr adsrSampler, int parameter, int faderValue)
    { 
        if(parameter == 0)
        {
            adsrSampler.changeAttack(faderValue);
        }
        else if(parameter == 1)
        {
            adsrSampler.changeDecay(faderValue);
        }
        else if(parameter == 2)
        {
            adsrSampler.changeRelease(faderValue);
        }    
    }
    
    void sendMidi(Midi midiSampler, Midi::MidiMessage midiMessage)
    {
        midiSampler.sendMidi(midiMessage);
    }
};
/*
 new UDT 5:
 */

int main()
{
    Synthesizer synth;
    Sampler samp;

    std::cout << "good to go!" << std::endl;
}
