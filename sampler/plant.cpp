/**
    CS-11 Sampler
    plant.cpp
    Purpose: Keep the plant alive!

    @author riselikethemoon
    @version 1.0 5/30/13
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include<fstream>
using namespace std;

class Score {
public:
    /**
        Constructor with no parameters, to initialize variables
    */
    Score();

    /**
        Constructor to initialize variables

        @param category: the type of points
        @param initialPoints: the points to start with
    */
    Score(string category, int initialPoints);

    /**
        Acesses private variable points

        @return points for given category
    */

    int getPoints();

    /**
        Accesses private variable name

        @return the name of the category
    */

    string name();

    /**
        Changes private variable points

        @param points to replace original points
    */
    void setPoints(int newPoints);

private:
    string category;
    int points;
};
    /**
        Allows player to allocate points to categories

        @param health: the vector of Scores
        @param points: the points assigned
    */
void allocate(vector<Score>& health, int points);

    /**
        Allows events to allocate points to categories

        @param health: the vector of Scores
        @param category: the category to add the points to
        @param points: the points assigned
    */
void allocate(vector<Score>& health, string category, int points);

    /**
        Prints image and initiates a single day

        @param health: the vector of Scores
        @param date: the number of days passed
    */
void day(vector<Score>& health, int date);

    /**
        Event triggered by too much water

        @param health: the vector of Scores
    */
void tooMuchWater(vector<Score>& health);

    /**
        Event triggered by too much food

        @param health: the vector of Scores
    */
void tooMuchFood(vector<Score>& health);

    /**
        Event triggered by too much love

        @param health: the vector of Scores
    */
void tooMuchLove(vector<Score>& health);

    /**
        Checks for death by assessing point levels of each Score

        @param health: the vector of Scores
    */
bool deathCheck(vector<Score>& health);

int main() {
    const int VECTOR_SIZE = 3;
    const int WATER = 0;
    const int FOOD = 1;
    const int LOVE = 2;
    const int WATER_POINTS = 7;
    const int FOOD_POINTS = 4;
    const int LOVE_POINTS = 7;
    const int LAST_DAY = 7;
    const int WIDE = 50;
    float VERSION = 1.0;

    Score water("Water", WATER_POINTS);
    Score food("Food", FOOD_POINTS);
    Score love("Love", LOVE_POINTS);

    vector<Score> health(VECTOR_SIZE);
    health[WATER] = water;
    health[FOOD] = food;
    health[LOVE] = love;


    // Intro
    cout << endl;
    cout << "           ___                       ___     " << endl;
    cout << "          (   )                     (   )    " << endl;
    cout << "   .-..    | |    .---.   ___ .-.    | |_    " << endl;
    cout << "  /    \\   | |   / .-| \\ (   )   \\  (   __)" << endl;
    cout << " ' .-,  ;  | |  (__) ; |  |  .-. .   | |     " << endl;
    cout << " | |  . |  | |    .'`  |  | |  | |   | | ___ " << endl;
    cout << " | |  | |  | |   / .'| |  | |  | |   | |(   )" << endl;
    cout << " | |  | |  | |  | /  | |  | |  | |   | | | | " << endl;
    cout << " | |  ' |  | |  ; |  ; |  | |  | |   | ' | | " << endl;
    cout << " | `-'  '  | |  ' `-'  |  | |  | |   ' `-' ; " << endl;
    cout << " | \\__.'  (___) `.__.'_. (___)(___)   `.__.  " << endl;
    cout << " | |                                         " << endl;
    cout << "(___)                                        " << endl;

    cout << setw(WIDE)  << left << endl << "* Welcome to Plant! *" << endl;
    cout << "(Version " << fixed << setprecision(1) << VERSION
        << " by riselikethemoon)" << endl;
    cout << setw(WIDE) << left << "\nYour best friend has asked you to watch"
    << endl << "her plant while she is out of town. She'll be gone for a"
    << endl << "week, so check on the plant every day and make sure it has"
    << endl << "the food, water, and love that it needs." << endl;

    cout << setw(WIDE) << left << endl << "* How the Game Works *" << endl;

    cout << setw(WIDE) << left << "Each day when you visit the plant,"
    << endl << "you'll get points to put toward its care. Be careful"
    << endl << "not to give it too much in any one category!" << endl;

    cout << "Press 'enter' twice to continue." << endl;
    cin.ignore();
    cin.get();

    for (int i = 1; i < (LAST_DAY + 1); i++) {
        if(deathCheck(health)) {
           day(health, i);
        }
    }

    ofstream fout;
    fout.open("plant_note_win.txt");
    if (fout.fail()) {
        cout << "You lost the note! Oh noes!" << endl;
    } else {
        fout << "Thanks for taking care of my plant!" << endl;
    }
    fout.close();
    cout << "\nYou won! The plant was still alive when your friend got home!"
    << "\nShe left a note on your door, too (see note_win.txt)\n"
    << endl << "* THE END *" << endl << endl;

return 0;

}

// Constructors

Score::Score() {
    category = "Unused Category";
    points = 0;
}

Score::Score(string categoryName, int initialPoints) {
    category = categoryName;
    points = initialPoints;
}

// Score member functions

int Score::getPoints() {
    return points;
}

string Score::name() {
    return category;
}

void Score::setPoints(int newPoints) {
        points = newPoints;
        return;
    }


// Non-member functions

void allocate(vector<Score>& health, int freePoints) {
    int pointsAdded = 0;
    const int WATER = 0;
    const int FOOD = 1;
    const int LOVE = 2;
    const int WIDTH = 8;
    const int VECTOR_SIZE = 3;

    int water = health[WATER].getPoints();
    int food = health[FOOD].getPoints();
    int love = health[LOVE].getPoints();

    cout << setw(WIDTH) << right << "Water:(" << water << "/10) ";
    for (int i = 0; i < water; i++) {
        cout << "*";
    }
    cout << endl;
    cout << setw(WIDTH) << right << "Food:(" << food << "/10) ";
    for (int i = 0; i < food; i++) {
        cout << "*";
    }
    cout << endl;
    cout <<  setw(WIDTH) << right << "Love:(" << love << "/10) ";
    for (int i = 0; i < love; i++) {
        cout << "*";
    }
    cout << endl;
    while (freePoints >0) {
        for (int i = 0; i < VECTOR_SIZE; i++) {
            cout << "You have " << freePoints << " extra points remaining"
                << endl;
            cout << "How many points to " << health[i].name() << "? ";
            cin >> pointsAdded;
            if (pointsAdded <= freePoints) {
                freePoints -= pointsAdded;
                int tempPoints = health[i].getPoints();
                tempPoints += pointsAdded;
                health[i].setPoints(tempPoints);

            } else {
                cout << "\nYou don't have that many points!" << endl;
                allocate(health, freePoints);
            }
        }
     cout << "That's it until tomorrow." << endl;
 return;
 }
}

void allocate(vector<Score>& health, int category, int points) {

    int tempPoints = health[category].getPoints();
    tempPoints += points;
    health[category].setPoints(tempPoints);
    return;
    }

void day(vector<Score>& health, int date) {
    cout << "\n----------------------------------------------------------------";
    cout << endl << "Day #" << date << endl;

    const int WATER = 0;
    const int FOOD = 1;
    const int LOVE = 2;
    const int USED = 2;
    const int DAY_POINTS = 6;
    const int POINT_MAX = 7;

    int water = health[WATER].getPoints();
    int food = health[FOOD].getPoints();
    int love = health[LOVE].getPoints();

    health[WATER].setPoints(water - USED);
    health[FOOD].setPoints(food - USED);
    health[LOVE].setPoints(love - USED);

    deathCheck(health);

    int highest = love;
    int category = LOVE;

    if (food >= highest) {
        highest = food;
        category = FOOD;
    }
    if (water >= highest) {
        highest = water;
        category = WATER;
    }
    if (highest > POINT_MAX && category == WATER) {
        tooMuchWater(health);
    }else if (highest > POINT_MAX && category == FOOD) {
        tooMuchFood(health);
    }else if (highest > POINT_MAX && category == LOVE) {
        tooMuchLove(health);
    } else {

    cout <<"           !                             \n";
    cout <<"           !!!             //            \n";
    cout <<"            !  !         ///             \n";
    cout <<"             !! !!     /  /              \n";
    cout <<"       ////////!  !  /   /               \n";
    cout <<"      ////______ ! !|   / ///////!       \n";
    cout <<"     ////        ! !!  / / _____   !     \n";
    cout <<"     //            !!!! //       !  !    \n";
    cout <<"             _______|_|_|_______   !!!   \n";
    cout <<"            (______  __  _______)    !!  \n";
    cout <<"            (_____  _   _______ )        \n";
    cout <<"             (___  _    _______)         \n";
    cout <<"             (____ __   _______)         \n";
    cout <<"              (___  _  _______)          \n";
    cout <<"               (_____________)           \n";
    cout << endl;
    }

    allocate(health, DAY_POINTS);
    return;

}

void tooMuchWater(vector<Score>& health) {
    const int FOOD_PENALTY = -2;
    const int LOVE_PENALTY = -2;
    const int FOOD = 1;
    const int LOVE = 2;

    cout << "               ______    \n";
    cout << "    _        ,',----.`.  \n";
    cout << "   '.`-.  .-' '----. ||  \n";
    cout << "      `.`-'--------| ;;  \n";
    cout << "        `.|--------|//   \n";
    cout << "          !         /    \n";
    cout << "          '--------'     \n";

    cout << "Your plant got too much water... causing the roots to rot."
        << " It will need lots of food and love to survive." << endl;
    int foodPoints = health[FOOD].getPoints();
    foodPoints += FOOD_PENALTY;
    health[FOOD].setPoints(foodPoints);

    int lovePoints = health[LOVE].getPoints();
    lovePoints += LOVE_PENALTY;
    health[LOVE].setPoints(lovePoints);

    deathCheck(health);

    return;
}

void tooMuchFood(vector<Score>& health) {
    const int WATER_PENALTY = -3;
    const int LOVE_PENALTY = 2;
    const int WATER = 0;
    const int LOVE = 2;

    cout << "               _._              \n";
    cout << "             .'   '.            \n";
    cout << "            /       !  ___      \n";
    cout << "     _.--. |     /  |.'   `'.   \n";
    cout << "   .'     `!   !|   /        !  \n";
    cout << "  /     _   !.=..=./  _.'    /  \n";
    cout << "  '.   .-'-.}`.<>.`{-'-.    /   \n";
    cout << "    ! .---.{ <>()<> }.--..-'    \n";
    cout << "    '/     _},'<>`.{_    `!     \n";
    cout << "   .'   .-'/ )=..=;`!`-    !    \n";
    cout << "  (         /  /| !         )   \n";
    cout << "   '-..___.'    :  '.___..-'    \n";
    cout << "          |      `   |          \n";
    cout << "          '.      _.'           \n";
    cout << "             `--.-'             \n";

    cout << "Your plant used all that tasty food to make a flower!"
    << " You love that! It sure used a lot of water, though..." << endl;
    int waterPoints = health[WATER].getPoints();
    waterPoints += WATER_PENALTY;
    health[WATER].setPoints(waterPoints);

    int lovePoints = health[LOVE].getPoints();
    lovePoints += LOVE_PENALTY;
    health[LOVE].setPoints(lovePoints);

    deathCheck(health);

    return;
}

void tooMuchLove(vector<Score>& health) {
    const int FOOD_PENALTY = -2;
    const int WATER_PENALTY = -2;
    const int FOOD = 1;
    const int WATER = 0;
    cout << "       @@@  @@@   \n";
    cout << "      @   @@   @  \n";
    cout << "      @    #   @  \n";
    cout << "       @  #   @   \n";
    cout << "        @  # @    \n";
    cout << "         @  @     \n";
    cout << "          @       \n";

    cout << "Wow, there, tiger. You love that plant a little too much!"
    << " That last hug broke off some leaves. It will need a lot of food"
    << " and water to heal itself." << endl;
    int foodPoints = health[FOOD].getPoints();
    foodPoints += FOOD_PENALTY;
    health[FOOD].setPoints(foodPoints);

    int waterPoints = health[WATER].getPoints();
    waterPoints += WATER_PENALTY;
    health[WATER].setPoints(waterPoints);

    deathCheck(health);

    return;
}

bool deathCheck(vector<Score>& health) {
    bool life = true;
    const int WATER = 0;
    const int FOOD = 1;
    const int LOVE = 2;
    const int POINT_MIN = 1;

    if (health[WATER].getPoints() < POINT_MIN) {
        cout << "The plant didn't have enough water!" << endl;
        life = false;
    }
    if (health[FOOD].getPoints() < POINT_MIN) {
        cout << "The plant didn't have enough food!" << endl;
        life = false;
    }
    if (health[LOVE].getPoints() < POINT_MIN) {
        cout << "The plant didn't have enough love!" << endl;
        life = false;
    }
    if (life == false) {
        cout << "You killed it :(" << endl;
            cout <<"                                         \n";
            cout <<"            __         .' '.             \n";
            cout <<"          _/__)        .   .       .     \n";
            cout <<"         (8|)_}}- .      .        .      \n";
            cout <<"          `!__)    '. . ' ' .  . '       \n";
            cout <<"                                         \n";
            cout <<"                 //////   ///            \n";
            cout <<"        //////////!!@X@X@////////////    \n";
            cout <<"       ///// __//___|_|_|__///__   ///   \n";
            cout <<"       ///  (______  __  _______)   ///  \n";
            cout <<"       ///  (_____      _______ )   ///   \n";
            cout <<"       //    (___  _    _______)  ///    \n";
            cout <<"       /     (____ __   _______)   //    \n";
            cout <<"              (___  _  _______)    /     \n";
            cout <<"               (_____________)           \n";
        cout << "Your neighbor left you a note when she got home...\n";
        ifstream fin;
        fin.open("plant_note_lose.txt");
        string note;

        if (fin.fail()) {
            cout << "Oops, you lost the note!\n";
            exit(-1);
        } else {
            getline(fin, note);
            cout << endl << note << endl;
        }
        fin.close();
        cout << endl << "* The End *" << endl << endl;
        exit(-2);
    }

    return life;
}
