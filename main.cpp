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

/*
 1)
 */

#include <iostream>
#include <vector>
 
struct Pet 
{
    bool isCat, isDog, isPetHappy, isPetHungry;
    int age;
    Pet() : isCat(false), isDog(false), isPetHappy(false), isPetHungry(false),
    age(0) { }

    void feedPet()
    {
        std::cout << "nom" << std::endl;
        isPetHungry = false;
        isPetHappy = true;
    }
    void status()
    {
        std::cout << isPetHungry << std::endl;
        std::cout << isPetHappy << std::endl;
    }
};

struct Human
{
    int numberOfViolations, numberOfCars, numberOfPets;
    std::string name;
    bool licenseIsValid, hasBike;

    Human() : numberOfViolations(0), numberOfCars(0), numberOfPets(0), name(""), licenseIsValid(false), hasBike(false){ }

    Pet acquirePet()
    {
        Pet pet;
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
            std::cout << "note on" << std::endl;
            ++ notesOn;
        }
    }
    void noteOff()
    {
        std::cout << "note off" << std::endl;
        -- notesOn;
    }
};

struct Sequencer
{
    bool isPlaying, playForward, playReverse;
    std::vector<int> notes;

    Sequencer() : isPlaying(0), playForward(1), playReverse(0),
    notes({}) {}

    void recordNote(int note)
    {
        notes.push_back(note);
    }

    void playBack(Synthesizer synth)
    {
        for( auto& n : notes )
        {   synth.noteOn();
            std::cout << n << std::endl; 
            synth.noteOff();
        }
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
    std::cout << "~~Human and Pets~~" << std::endl;
    Human jason;
    jason.name = "Jason Perez";
    std::cout << "starting number of pets: " << jason.numberOfPets << std::endl;
    Pet ourPet = jason.acquirePet();
    std::cout << "number of pets, after acquiring one: " << jason.numberOfPets << std::endl;
    std::cout << jason.isPetHungry(ourPet) << std::endl;
    ourPet.feedPet();
    std::cout << jason.isPetHungry(ourPet) << std::endl;

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

    std::cout << "~~Car and Driver~~" << std::endl;
    Car jetta;
    jetta.addDriver(jason);
    std::cout << jetta.driverName << " has " << jason.numberOfCars << " cars" << std::endl; 
}
