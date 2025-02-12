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

    if(fin)
    {
        string line;
        while(getline(fin, line))
        {
            Game stud;
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
int main() {

    Game stud;
    stud.year = 21;
    stud.name = "Peter";
    stud.rating = 1.7;
    stud.developer = "peter@oscorp.com";
    //display(stud);
//    cout <<left<< setw(15)<< "Name" <<setw(5) <<"year"<<setw(10)
//         << "rating" <<setw(50) <<"developer"<<endl;
    vector<Game> v;
    load("CA1.txt", v);

    for(Game &s: v)
    {
        s.year *=2;
    }
    auto func =
            [](Game s1, Game s2){return s1.rating > s2.rating;};
    sort(v.begin(), v.end(), func);
    /*
    for(vector<Student>::iterator iter = v.begin();
    iter != v.end();
    iter++)
    {
        display(*iter);
    }*/
    writeToFile(v);

    return 0;
}
