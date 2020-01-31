/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()



/*
 1)
 */

#include <iostream>
#include <vector>
 
struct Pet 
{
    bool isCat, isDog, isPetHappy, isPetHungry;
    int age;
    double foodLevel;
    std::string name;

    Pet(std::string petType, std::string petName) : isCat(false), isDog(false), isPetHappy(false), isPetHungry(false), age(0), foodLevel(10.0), name(petName)
    { 
        std::cout << "A " << petType << " named " << petName << " is born!" << std::endl;

        if(petType == "cat")
        {
            std::cout << "meow" << std::endl;
            isCat = true;
        }
        else if (petType == "dog")
        {
            std::cout << "woof" << std::endl;
            isDog = false;
        }
        else {
            //handle other pet types
        }
    }

    void feed()
    {
        std::cout << "nom" << std::endl;
        isPetHungry = false;
        isPetHappy = true;
    }

    void walk(int howLong)
    {   
        if(isPetHungry == false)
        {
            std::cout << "walking " << name << " for " << howLong << " minutes " << std::endl;
            while(howLong > 0)
            {
                std::cout << ".";
                howLong --;
                foodLevel = foodLevel - 0.25;

                if(foodLevel < 5 and foodLevel > 1)
                {
                    std::cout << name << " is getting hungry!!" << std::endl;
                }

                if(foodLevel < 1)
                {
                    std::cout << name << " is too hungry to walk, time to eat!" << std::endl;
                    howLong = 0;
                    isPetHungry = true;
                }
            }
            std::cout << std::endl;
        }
        else 
        {
            std::cout << name << " is hungry, let's eat first! " << std::endl;
        }
        
        std::cout << "Done walking " << name << std::endl;
        isPetHappy = true;
    }

    void status()
    {
        std::cout << name;
        isPetHungry ?  std::cout << " is" : std::cout << " is not";
        std::cout << " hungry" << std::endl;
        
        std::cout << "food level: " << foodLevel << std::endl;

        std::cout << name;
        isPetHappy ?  std::cout << " is" : std::cout << " is not";
        std::cout << " happy" << std::endl;
    }
};

struct Human
{
    int numberOfViolations, numberOfCars, numberOfPets;
    std::string name;
    bool licenseIsValid, hasBike;

    Human() : numberOfViolations(0), numberOfCars(0), numberOfPets(0), name(""), licenseIsValid(false), hasBike(false){ }

    Pet acquirePet(std::string petType, std::string petName)
    {
        Pet pet(petType, petName);
        ++ numberOfPets;
        return pet;
    }

    bool isDriverAllowedToDrive();
    std::string isPetHungry(Pet ourPet)
    {
        if(ourPet.isPetHungry)
        {
            return "Pet is hungry!";
        }
        else 
        {
            return "Pet is not hungry";
        }
    }
};

/*
 2)
 */

struct Synthesizer 
{
    unsigned int polyphony, notesOn;
    Synthesizer() : polyphony(16), notesOn(0) {}

    void noteOn()
    {
        if(notesOn < polyphony) 
        {
            std::cout << " -note on- ";
            ++ notesOn;
        }
    }
    void noteOff()
    {
        std::cout << " -note off- ";
        -- notesOn;
    }
};

struct Sequencer
{
    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;

    Sequencer() : isPlaying(0), playForward(true), playReverse(false), notes({}) {}

    void recordNote(int note)
    {
        notes.push_back(note);
    }

    void playBack(Synthesizer synth)
    {
        if(playForward)
        {
            std::cout << "playing forward:: ";
            for( auto& n : notes )
            {   
                std::cout << n << " "; 
                synth.noteOn();
                synth.noteOff();
            }
        }

        if(playReverse)
        {
            std::cout << "playing reverse:: ";
            for( auto n = notes.rbegin(); n != notes.rend(); ++n)
            {   
                std::cout << *n << " "; 
                synth.noteOn();
                synth.noteOff();
            }
        }
        std::cout << std::endl;
    }

    void setForwardPlayback()
    {
        playForward = true;
        playReverse = false;
    }

    void setReversePlayback()
    {
        playForward = false;
        playReverse = true;
    }
};

/*
 3)
 */

struct Playlist 
{
    bool isSharable;
    std::vector<int> songs;
    double idOfCoverImage;
    
    Playlist() : isSharable(1), idOfCoverImage(8717241) {}

    void addSongToPlaylist(int);
    void listSongsInPlaylist();
};

void Playlist::listSongsInPlaylist()
{
    for( auto& s : songs )
    {
        std::cout << s << std::endl; 
    }
}

void Playlist::addSongToPlaylist(int id)
{
    songs.push_back(id);
}

/*
 4)
 */

struct Student
{
    float currentGPA;
    std::string name;

    Student() : currentGPA(0.f), name("") {}

    double calculateGPA();
    double calculateTotalDaysMissed();
};


struct Class
{
    int daysMissed;
    float currentGrade;
    std::vector<std::string> students;

    Class() : daysMissed(0), currentGrade(0.f), students({}) {}

    void addMissedDay()
    {
        ++daysMissed;
    }

    void addStudent(Student student)
    {
        students.push_back(student.name);
    }
};

/*
 5)
 */

struct RadioShow
{
    bool transmitterIsActive;
    std::string showDay, featuredBand;
    double showTime;
    int hostID;

    RadioShow() : transmitterIsActive(false), showDay(""), featuredBand(""),
    showTime(0), hostID(0) {}
   
    void updateShowTime(int updatedHostID, std::string updatedShowDay, double updatedShowTime)
    {
        hostID = updatedHostID;
        showDay = updatedShowDay;
        showTime = updatedShowTime;
    }
};

/*
 6)
 */

struct Car
{
    bool isRegistered, isSmogged;
    std::string driverName;

    Car() : isRegistered(false), isSmogged(false), driverName("") {}

    void smogCar()
    {
        isSmogged = true;
    }

    void registerCar()
    {   
        isRegistered = true;
    }

    void addDriver(Human human)
    {
        driverName = human.name;
        ++ human.numberOfCars;
    }
};

/*
 7)
 */

struct Bike
{
    int numberOfGears;
    std::string bikeOwner;
    bool hasDiscBrakes, hasCarbonFrame;

    Bike() : numberOfGears(0), bikeOwner(""), hasDiscBrakes(false), 
    hasCarbonFrame(false) {}

    void addBicyclist(Human human)
    {
        human.hasBike = true;
        bikeOwner = human.name;
    }
};

/*
 8)
 */

struct Album 
{
    int numberOfTracks;
    bool isReleased;
    Album() : numberOfTracks(0), isReleased(false) {}
};

struct Artist
{
    Album album;
    double genreId;
    bool isActive;

    Artist() : genreId(0), isActive(true) {} 

    void addAlbumToArtist(Album addedAlbum)
    {
        album = addedAlbum;
    }
};

/*
 9)
 */

struct Visit 
{
    int visitDate;
    float icdCode;
    char icdPrefix;
};

struct Patient
{
    Human patient;
    bool hasHadAnnual;
    std::string doctor;
    int lastVisitDate;

    Patient() : hasHadAnnual(false), doctor(""), lastVisitDate(0) {}

    void addVisit(Visit visit, std::string visitDoctor)
    {
        lastVisitDate = visit.visitDate;
        doctor = visitDoctor;
    }
};

/*
 10)
 */

struct Band
{
    std::string name;
    Artist member1, member2;
    bool isOnTour;
    RadioShow promotionalRadioShow;

    Band() : name(""), isOnTour(false) {}

    void addBandToRadioshow(RadioShow rs)
    {
        rs.featuredBand = name;
    }
};

int main()
{
    Example::main();
    std::cout << "~~Human and Pets~~" << std::endl;
    Human jason;
    jason.name = "Jason Perez";
    std::cout << "starting number of pets: " << jason.numberOfPets << std::endl;
    Pet ourPet = jason.acquirePet("cat", "Clementine");
    ourPet.walk(10);
    ourPet.walk(30);
    ourPet.status();

    std::cout << "~~Synthesizers and Sequencers~~" << std::endl;
    Synthesizer moog;
    moog.noteOn();
    moog.noteOn();
    std::cout << "play two, how many notes on: " << moog.notesOn << std::endl;
    moog.noteOff();
    std::cout << "remove one note, how many notes on: " << moog.notesOn << std::endl;    

    Sequencer sequencer;
    sequencer.recordNote(24);
    sequencer.recordNote(72);
    sequencer.playBack(moog);
    sequencer.setReversePlayback();
    sequencer.playBack(moog);
}
