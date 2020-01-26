
#include <iostream>
#include <vector>
using namespace std;
 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below. test comment
 */


struct Limb 
{
    int steps;
    void stepForward();
    void stepBackward();
    int stepSize();
};

struct Person
{   
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled = 0;
    Limb leftFoot, rightFoot;
    void run(int howFast, bool startWithLeftFoot);
};

int Limb::stepSize()
{
    return 1;
}

void Limb::stepForward()
{
    steps++;
}
void Limb::stepBackward()
{
    steps--;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() +rightFoot.stepSize();
}


 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 1)
 */
 
struct Pet 
{
    int age;
    bool isCat, isDog, isPetHappy;
    bool isPetHungry = true;
    void feedPet();
    void status();
};

struct Human
{
    Pet pet;
    string name;

    bool licenseIsValid;
    bool hasBike;
    int numberOfViolations;
    int numberOfCars = 0;
    // Car car;
    bool isDriverAllowedToDrive();
    bool isPetHungry(Pet);
};

bool Human::isPetHungry(Pet ourPet)
{
    if(ourPet.isPetHungry){
        std::cout << "Pet is hungry!" << std::endl;
        return true;
    }
    else 
    {
        return false;
    }
}

void Pet::feedPet()
{
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

struct Sequencer
{
    bool isPlaying = 0;
    bool playForward = 1;
    bool playReverse = 0;
    vector<int> notes;

    void recordNote(int);
    void playBack();
};

struct Synthesizer 
{
    unsigned int polyphony = 0;
    unsigned int notesOn = 0;
    bool multitimbral;

    Sequencer sequencer;
    void noteOn();
    void noteOff();
};

void Synthesizer::noteOn()
{
    if(notesOn < polyphony) {
        notesOn ++;
    }
}

void Synthesizer::noteOff()
{
    notesOn --;
}


void Sequencer::recordNote(int note)
{
    notes.push_back(note);
}

void Sequencer::playBack()
{
    vector<int>::iterator it;   
    for(it = notes.begin(); it != notes.end(); it++) 
    {
        cout << *it <<" "; 
    }
}

/*
 3)
 */

struct Playlist 
{
    bool isSharable = 1;
    vector<int> songs;
    double idOfCoverImage = 8717241; //ID for default image

    void addSongToPlaylist(int);
    void deleteSongFromPlaylist(int);
    void listSongsInPlaylist();
};

void Playlist::listSongsInPlaylist()
{
    vector<int>::iterator it;   
    for(it = songs.begin(); it != songs.end(); it++) 
    {
        cout << *it <<" "; 
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
    string name;
    float currentGPA;

    double calculateGPA();
    double calculateTotalDaysMissed();
};


struct Class
{
    vector<string> students;
    float currentGrade;
    int daysMissed = 0;

    void addMissedDay();
    void addStudent(Student);
};


void Class::addMissedDay()
{
    daysMissed++;
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
    string showDay;
    string featuredBand;
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
    string driverName;
    bool isRegistered;
    bool isSmogged;

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
    human.numberOfCars ++;
}


/*
 7)
 */

struct Bike
{
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
    int numberOfTracks;
    bool isReleased;
};

struct Artist
{
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
    string name;
    Artist member1;
    Artist member2;
    RadioShow promotionalRadioShow;
    void addBandToRadioshow(RadioShow);
};

void Band::addBandToRadioshow(RadioShow rs)
{
    rs.featuredBand = name;
}

int main()
{

}
