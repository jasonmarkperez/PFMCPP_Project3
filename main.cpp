/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



/*
 1)
 */

#include <iostream>
#include <vector>
 
struct Pet 
{
    Pet()
    { 
        isPetHungry = true;
        isPetHappy = true;
        age = 0;
    }
    int age;
    bool isCat, isDog, isPetHappy, isPetHungry;
    void feedPet();
    void status();
};

struct Human
{
    Human() 
    { 
        numberOfCars = 0;
        numberOfPets = 0;
    }
    std::string name;

    bool licenseIsValid, hasBike;
    int numberOfViolations, numberOfCars, numberOfPets;

    Pet acquirePet();
    bool isDriverAllowedToDrive();
    std::string isPetHungry(Pet);
};

std::string Human::isPetHungry(Pet ourPet)
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

Pet Human::acquirePet()
{
    Pet pet;
    ++ numberOfPets;
    return pet;
}

void Pet::feedPet()
{
    std::cout << "nom" << std::endl;
    isPetHungry = false;
    isPetHappy = true;
}

void Pet::status(){
    std::cout << isPetHungry << std::endl;
    std::cout << isPetHappy << std::endl;
}

/*
 2)
 */

struct Synthesizer 
{
    Synthesizer()
    {
        polyphony = 16;
        notesOn = 0;
    }
    unsigned int polyphony, notesOn;
    bool multitimbral;

    void noteOn();
    void noteOff();
};

void Synthesizer::noteOn()
{
    if(notesOn < polyphony) 
    {
        std::cout << "note on" << std::endl;
        ++ notesOn;
    }
}

void Synthesizer::noteOff()
{
    std::cout << "note off" << std::endl;
    -- notesOn;
}

struct Sequencer
{
    Sequencer() 
    {
        isPlaying = 0;
        playForward = 1;
        playReverse = 0;
    }
    
    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;

    void recordNote(int);
    void playBack(Synthesizer synth);
};

void Sequencer::recordNote(int note)
{
    notes.push_back(note);
}

void Sequencer::playBack(Synthesizer synth)
{
    for( auto& n : notes )
    {   synth.noteOn();
        std::cout << n << std::endl; 
        synth.noteOff();
    }
}

/*
 3)
 */

struct Playlist 
{
    Playlist()
    {
        isSharable = 1;
        idOfCoverImage = 8717241; //ID for default image
    }
    bool isSharable;
    std::vector<int> songs;
    double idOfCoverImage;

    void addSongToPlaylist(int);
    void deleteSongFromPlaylist(int);
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
    Student()
    {
        currentGPA = 0.f;
    }

    std::string name;
    float currentGPA;

    double calculateGPA();
    double calculateTotalDaysMissed();
};


struct Class
{
    Class()
    {
        daysMissed = 0;
    }
    std::vector<std::string> students;
    float currentGrade;
    int daysMissed;

    void addMissedDay();
    void addStudent(Student);
};


void Class::addMissedDay()
{
    ++daysMissed;
}

void Class::addStudent(Student student)
{
    students.push_back(student.name);
}

/*
 5)
 */

struct RadioShow
{
    RadioShow()
    {
        transmitterIsActive = false;
    }
    std::string showDay, featuredBand;
    bool transmitterIsActive;
    double showTime;
    int hostID;
    void updateShowTime(int, std::string, double);
};

void RadioShow::updateShowTime(int updatedHostID, std::string updatedShowDay, double updatedShowTime)
{
    hostID = updatedHostID;
    showDay = updatedShowDay;
    showTime = updatedShowTime;
}

/*
 6)
 */

struct Car
{
    
    Car()
    {
        isRegistered = false;
        isSmogged = false;
    }

    std::string driverName;
    bool isRegistered, isSmogged;

    void registerCar();
    void smogCar();
    void addDriver(Human);
};

void Car::smogCar()
{
    isSmogged = true;
}

void Car::registerCar()
{   
    isRegistered = true;
}

void Car::addDriver(Human human)
{
    driverName = human.name;
    ++ human.numberOfCars;
}

/*
 7)
 */

struct Bike
{
    Bike()
    {
        hasDiscBrakes = false;
        hasCarbonFrame = false;
    }
    int numberOfGears;
    std::string bikeOwner;
    bool hasDiscBrakes;
    bool hasCarbonFrame;
    void addBicyclist(Human);
};

void Bike::addBicyclist(Human human)
{
    human.hasBike = true;
    bikeOwner = human.name;
}

/*
 8)
 */

struct Album 
{
    Album()
    {
        isReleased = false;
    }

    int numberOfTracks;
    bool isReleased;

};

struct Artist
{
    Artist()
    {
        isActive = true;
    }

    Album album;
    double genreId;
    bool isActive;

    void addAlbumToArtist(Album);
};

void Artist::addAlbumToArtist(Album addedAlbum)
{
    album = addedAlbum;
}

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
    Patient()
    {
        hasHadAnnual = false;
    }

    Human patient;
    bool hasHadAnnual;
    std::string doctor;
    int lastVisitDate;

    void addVisit(Visit, std::string);
};

void Patient::addVisit(Visit visit, std::string visitDoctor)
{
    lastVisitDate = visit.visitDate;
    doctor = visitDoctor;
}

/*
 10)
 */

struct Band
{
    Band()
    {
        isOnTour = false;
    }
    std::string name;
    Artist member1;
    Artist member2;
    bool isOnTour;
    RadioShow promotionalRadioShow;
    void addBandToRadioshow(RadioShow);
};

void Band::addBandToRadioshow(RadioShow rs)
{
    rs.featuredBand = name;
}

int main()
{
    Example::main();

    Human jason;
    jason.name = "Jason Perez";
    std::cout << "starting number of pets: " << jason.numberOfPets << std::endl;
    Pet ourPet = jason.acquirePet();
    std::cout << "number of pets, after acquiring one: " << jason.numberOfPets << std::endl;
    std::cout << jason.isPetHungry(ourPet) << std::endl;
    ourPet.feedPet();
    std::cout << jason.isPetHungry(ourPet) << std::endl;

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

    Car jetta;
    jetta.addDriver(jason);
    std::cout << jetta.driverName << " has " << jason.numberOfCars << " cars" << std::endl; //I'm confused why this isn't 1
}
