#include <iostream>
#include <vector>
using namespace std;
/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate a few of your user-defined types in the main function at the bottom of that file, and call some of those member functions.

 3) make them print out something interesting via std::cout

 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.

 example:
 */

namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.


/*
 1)
 */
 
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
    string name;

    bool licenseIsValid, hasBike;
    int numberOfViolations, numberOfCars, numberOfPets;

    Pet acquirePet();
    bool isDriverAllowedToDrive();
    string isPetHungry(Pet);
};

string Human::isPetHungry(Pet ourPet)
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
    cout << "nom" << endl;
    isPetHungry = false;
    isPetHappy = true;
}

void Pet::status(){
    cout << isPetHungry << endl;
    cout << isPetHappy << endl;
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
        cout << "note on" << endl;
        ++ notesOn;
    }
}

void Synthesizer::noteOff()
{
    cout << "note off" << endl;
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
    vector<int> notes;

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
        cout << n << endl; 
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
    vector<int> songs;
    double idOfCoverImage;

    void addSongToPlaylist(int);
    void deleteSongFromPlaylist(int);
    void listSongsInPlaylist();
};

void Playlist::listSongsInPlaylist()
{
    for( auto& s : songs )
    {
        cout << s << endl; 
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

    string name;
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
    vector<string> students;
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
    string showDay, featuredBand;
    bool transmitterIsActive;
    double showTime;
    int hostID;
    void updateShowTime(int, string, double);
};

void RadioShow::updateShowTime(int updatedHostID, string updatedShowDay, double updatedShowTime)
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

    string driverName;
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
    string bikeOwner;
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
    string doctor;
    int lastVisitDate;

    void addVisit(Visit, string);
};

void Patient::addVisit(Visit visit, string visitDoctor)
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
    string name;
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
    // Example::main();

    Human jason;
    jason.name = "Jason Perez";
    cout << "starting number of pets: " << jason.numberOfPets << endl;
    Pet ourPet = jason.acquirePet();
    cout << "number of pets, after acquiring one: " << jason.numberOfPets << endl;
    cout << jason.isPetHungry(ourPet) << endl;
    ourPet.feedPet();
    cout << jason.isPetHungry(ourPet) << endl;

    Synthesizer moog;
    moog.noteOn();
    moog.noteOn();
    cout << "play two, how many notes on: " << moog.notesOn << endl;
    moog.noteOff();
    cout << "remove one note, how many notes on: " << moog.notesOn << endl;

    Sequencer sequencer;
    sequencer.recordNote(24);
    sequencer.recordNote(72);
    sequencer.playBack(moog);

    Car jetta;
    jetta.addDriver(jason);
    cout << jetta.driverName << " has " << jason.numberOfCars << " cars" << endl; //I'm confused why this isn't 1
}
