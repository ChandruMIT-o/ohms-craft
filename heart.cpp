#include <iostream>
#include <chrono>
#include <thread>
#include "ohmcraft.cpp"
using namespace std;

void animateTitle2(const string& title) {
    int length = title.length() + 10;
    int animationDelay = 200;

    for (int i = 0; i < 10; ++i) {
        system("cls");
        cout << "\033[1;31m"; // Set text color to blue and bold
        for (int j = 0; j < length + i * 2; ++j) {
            cout << "-";
        }
        cout << endl;

        for (int j = 0; j < i; ++j) {
            cout << " ";
        }
        cout << "% " << title << " %" << endl;

        for (int j = 0; j < length + i * 2; ++j) {
            cout << "-";
        }
        cout << "\033[0m"; // Reset text color to default
        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(animationDelay));
    }
}

void printWelcomeMessage() {
    int animationDelay = 400;
    cout << "\033[1;32m"; // Set text color to green and bold
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "|               Welcome (Please Read! Took So much to write....)           |" << endl;
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << "|       ==========================================================         |" << endl;
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << "|  This toolkit presents an API designed for handling Multi-Graphs,        |" << endl;
    cout << "|  equipped with novel algorithms for node-based operations.               |" << endl;
    cout << "|  Each node has the ability to establish connections with multiple        |" << endl;
    cout << "|  other nodes, and it allows for the existence of multiple links between  |" << endl;
    cout << "|  nodes. The underlying concept is highly adaptable and has been          |" << endl;
    cout << "|  successfully applied to two distinct applications. Notably, this        |" << endl;
    cout << "|  impressive toolkit is the sole creation of Chandru J.                   |" << endl;
    cout << "|  and can be reached via email at chandrukavin0503@gmail.com.             |" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "\033[0m"; // Reset text color to default
    cout << endl;
}

int whereToEnter(){
    int animationDelay = 400;
    cout << "\033[35m";
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "|                          OHMCRAFT             [Option: 1]                |" << endl;
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << "|       ==============================================================     |" << endl;
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << "|  This toolkit provides an API for a Graph Manipulation Model dedicated   |" << endl;
    cout << "|  for Circuit Analysis With Peculiar New Algorithms for Nodal Fusion      |" << endl;    
    cout << "|  and my personal Circuit Solving Algorithm called Nodal Reduction        |" << endl; 
    cout << "|  using Prioritized Recursive Backtracking.                               |" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "\033[0m";

    this_thread::sleep_for(chrono::milliseconds(animationDelay));

    cout << "\033[1;34m";
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "|                      Road Network Analysis    [Option: 2]                |" << endl;
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << "|       ==============================================================     |" << endl;
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << "|  This toolkit provides an API for a Graph Manipulation Model dedicated   |" << endl;
    cout << "|  to Road Network Analysis with Advanced Algorithms for Finding Shortest  |" << endl;    
    cout << "|  Distances and Paths between Multiple Locations. It stores data such as  |" << endl; 
    cout << "|  Road Distances between Nodes for comprehensive analysis.                |" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "\033[0m";
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    this_thread::sleep_for(chrono::milliseconds(animationDelay));
    cout << endl << ">>> Which one would you like to checkout? (1/2) > ";
    int option;
    cin >> option;
    const int iterations = 10;

    cout << endl;

    for (int i = 0; i < iterations; ++i) {
        cout << "\033[1;33mLoading................" << ((i % 2 == 0) ? "/" : "\\") << "\r";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout << "\033[0m" << endl;
    return option;
}
                                                           
int main(){
    int option,opt;
    do{
        animateTitle2("Non-Directional Multi-Graph Manipulation Toolkit");
        printWelcomeMessage();

        option = whereToEnter();
        if(option == 1){
            main2();
            cout << ">>> Want to Continue or Exit? (1/2) > ";
            cin >> opt;
        }
        else if(option == 2){
            cout << ">>> Want to Continue or Exit? (1/2) > ";
            cin >> opt;
        }
        else{
            cout << endl << ">>> Invalid Option (Enter Again) (1/2) > ";
            cin>> option;
        }

        if(opt == 2){
            break;
        }
    }
    while(option != 0);

    system("cls");
    
    cout << "\033[1;31m"; // Set text color to red and bold
    cout << "------------------------------------------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "|  Thank you for using the Non-Directional Multi-Graph     |" << endl;
    cout << "|        Manipulation Toolkit! See you again!              |" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "------------------------------------------------------------" << endl;
    cout << "\033[0m"; // Reset text color to default

    return 0;
}
