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
    int index;
    string name;
    double rating;
    string developer;
    int year;
};


void display(const Game &stud)
{
    cout <<left
    << setw(15)<< stud.name
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
void writeToFile(const vector<Game> &data,int idnexq)
{
    int index= idnexq;
    ofstream out("Out.txt"+index);
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
    stud.index=0;
    stud.year = 0;
    stud.name = "";
    stud.rating = 0.0;
    stud.developer = "";

    vector<Game> v;
    vector<Game> w;
    load("Ca_data.txt", v);
    load("Ca_data.txt", w);

    for(Game &s: v)
    {
        s.year=s.year;
    }
    auto func2 =
    [](Game s1, Game s2){return s1.rating < s2.rating;};
    sort(v.begin(), v.end(), func2);
    auto func =
            [](Game s1, Game s2){return s1.rating > s2.rating;};
    sort(w.begin(), w.end(), func);

    //int count_under18 = count_if(v.begin(), v.end(), [] (Game s1) { return s1.rating < 18; } );
   // cout <<  << count_under18 << '\n';

    for(vector<Game>::iterator iter2 = w.begin(); iter2 != w.end(); iter2++)
    {
        display(*iter2);

        writeToFile(w,1);

        return 0;
    }
    for(vector<Game>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        display(*iter);

        writeToFile(v,2);

        return 0;
    }


}
