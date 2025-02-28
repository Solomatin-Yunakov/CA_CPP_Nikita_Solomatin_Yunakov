#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Game
{

    string name;
    double rating;
    string developer;
    int year;
};


void display(const Game &stud)
{
    cout <<left
    << setw(15)<< stud.name
    <<setw(5) <<stud.year
    <<setw(10)<< stud.rating
    <<setw(50)<<stud.developer
    <<endl;

}
void parseLine(string line,Game &stud)
{

    string temp;
    stringstream ss(line);
    getline(ss, stud.name, ',');
    getline(ss, temp, ',');
    stud.rating = stod(temp);

    getline(ss, stud.developer, ',');
    getline(ss, temp, ',');
    stud.year = stoi(temp);

}

void load(string Ca_data, vector<Game> &data)
{

    ifstream fin(Ca_data);
    cout << "File load." <<endl;
    cout << Ca_data <<endl;
    if(fin)
    {
        string line;
        while(getline(fin, line))
        {
            Game stud;
            cout << line <<endl;

            parseLine(line, stud);
            data.push_back(stud);

        }
        fin.close();

    }
    else
    {
        cout << "Error opening file." <<endl;
    }
}
void writeToFile(const vector<Game> &data)
{

    ofstream out("Out.txt");
    if(out)
    {
        for(int i = 0; i < data.size();i++)
        {
            out <<left

                << setw(15)<< data[i].name
                <<setw(50)<<data[i].developer
                <<setw(5) <<data[i].year
                <<setw(10)<< data[i].rating
                <<endl;
        }
        out.close();
    }
    else
    {
        cout << "Error opening file."<<endl;
    }
}
void displayNameByDev(const vector<Game> &data,const string &name)
{
    bool found = false;
    for(int i = 0; i < data.size();i++) {
        if(data[i].developer == name) {
            found = true;
            cout << left << setw(15) << data[i].name << data[i].developer;
        }
    }
    if(!found) {
        cout << "Not found" <<endl;
    }
}
int findGameYears(const vector<Game> &data) {
    int sum = 0;
    int highest = 0;
    int lowest = 2016;
    int counter=0;
    for(int i = 0; i < data.size();i++) {

        sum += data[i].year;
        counter++;
        if(data[i].year > highest) {
            highest = data[i].year;
        }
        if(data[i].year < lowest) {
            lowest = data[i].year;
        }
    }
    cout << "Highest year: " << highest << endl;
    cout << "Lowest year: " << lowest << endl;
    return sum/counter;
}
int main() {
    Game stud;

    stud.year = 0;
    stud.name = "";
    stud.rating = 0.0;
    stud.developer = "";

    vector<Game> v;

    load("Ca_data.txt", v);

    for(Game &s: v)
    {
        s.year=s.year;
    }
   /*
    *I tried to made a menu to make more user fiendly
    *But all methods stop working corectly when they start running
    *from if statements
    *
    * cout<< "Type number of operation which you want to do";
    cout<< "\n 1 Find Name by Developer Name\n 2 Find years of games\n 3 Show all Game inforamtio\n";
    load("Ca_data.txt", v);
    int choice;
    cin >> choice;
    if(choice == 1) {
        vector<Game> v;
        int avarageyear=findGameYears(v);
        cout<<"Your avageyear is: "<<avarageyear<<endl;
        for(Game &s: v)
        {
            s.year=s.year;
        }
    }
    else if(choice == 2) {
    load("Ca_data.txt", v);
        vector<Game> v;
        string username;
        cout <<"Enter developer Name to find Game name"<< '\n';
        cin>>username;
        getline(cin, username);
        displayNameByDev(v,username);
    }
    else if(choice == 3) {
        load("Ca_data.txt", v);
    }
*/




    string username;
    cout <<"Enter developer Name to find Game name"<< '\n';
    getline(cin, username);

   displayNameByDev(v,username);
   cout << '\n';
    int avarageyear=findGameYears(v);
    cout<<"Your avageyear is: "<<avarageyear<<endl;
    auto func2 =
    [](Game s1, Game s2){return s1.rating > s2.rating;};
    sort(v.begin(), v.end(), func2);


    //int count_under18 = count_if(v.begin(), v.end(), [] (Game s1) { return s1.rating < 18; } );
   // cout <<  << count_under18 << '\n';


    for(vector<Game>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        display(*iter);

        writeToFile(v);

        return 0;
    }



}
