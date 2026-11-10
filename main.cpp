#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class TrafficSystem
{
private:
    int lanesA, lanesB, totalLanes;
    int trafficA, trafficB;

public:
    TrafficSystem()
    {
        lanesA = 1;
        lanesB = 2;
        totalLanes = 3;
        trafficA = 0;
        trafficB = 0;
    }

    void selectRoad()
    {
        int choice;

        cout << "\n1. Three Lane Road";
        cout << "\n2. Four Lane Road";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            totalLanes = 3;
            lanesA = 1;
            lanesB = 2;
        }
        else if (choice == 2)
        {
            totalLanes = 4;
            lanesA = 2;
            lanesB = 2;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    void enterTraffic()
    {
        cout << "\nEnter vehicles in Direction A: ";
        cin >> trafficA;

        cout << "Enter vehicles in Direction B: ";
        cin >> trafficB;

        if (trafficA < 0 || trafficB < 0)
        {
            cout << "Invalid traffic count!\n";
            trafficA = 0;
            trafficB = 0;
        }
    }

    void analyzeTraffic()
    {
        cout << "\nTraffic Analysis:\n";

        if (trafficA >= trafficB * 1.25 && trafficA > trafficB)
        {
            lanesA = totalLanes - 1;
            lanesB = 1;
            cout << "Direction A has higher traffic.\n";
        }
        else if (trafficB >= trafficA * 1.25 && trafficB > trafficA)
        {
            lanesB = totalLanes - 1;
            lanesA = 1;
            cout << "Direction B has higher traffic.\n";
        }
        else
        {
            cout << "Traffic is balanced. Keeping current allocation.\n";
        }

        cout << "\nBarrier position updated successfully.\n";
        displayRoad();
        saveHistory();
    }

    void displayRoad()
    {
        cout << "\n========== ROAD LAYOUT ==========\n";

        cout << "Direction A ---> ";

        for (int i = 0; i < lanesA; i++)
            cout << "[ A ] ";

        cout << "|| BARRIER || ";

        for (int i = 0; i < lanesB; i++)
            cout << "[ B ] ";

        cout << "<--- Direction B\n";
    }

    void displayStatistics()
    {
        cout << "\n========== TRAFFIC STATISTICS ==========\n";
        cout << "Direction A Vehicles: " << trafficA << endl;
        cout << "Direction B Vehicles: " << trafficB << endl;
        cout << "Direction A Lanes: " << lanesA << endl;
        cout << "Direction B Lanes: " << lanesB << endl;
    }

    void saveHistory()
    {
        ofstream file("traffic_history.txt", ios::app);

        if (file.is_open())
        {
            file << "Direction A: " << trafficA
                 << " | Direction B: " << trafficB
                 << " | Lanes A: " << lanesA
                 << " | Lanes B: " << lanesB << endl;

            file.close();
        }
    }

    void viewHistory()
    {
        ifstream file("traffic_history.txt");
        string line;

        cout << "\n========== TRAFFIC HISTORY ==========\n";

        if (!file.is_open())
        {
            cout << "No history available.\n";
            return;
        }

        while (getline(file, line))
            cout << line << endl;

        file.close();
    }
};

int main()
{
    TrafficSystem system;
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n INTELLIGENT TRAFFIC MANAGEMENT";
        cout << "\n====================================";
        cout << "\n1. Select Road Configuration";
        cout << "\n2. Enter Traffic Density";
        cout << "\n3. Analyze Traffic and Move Barrier";
        cout << "\n4. Display Road Layout";
        cout << "\n5. View Traffic Statistics";
        cout << "\n6. View Traffic History";
        cout << "\n7. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                system.selectRoad();
                break;

            case 2:
                system.enterTraffic();
                break;

            case 3:
                system.analyzeTraffic();
                break;

            case 4:
                system.displayRoad();
                break;

            case 5:
                system.displayStatistics();
                break;

            case 6:
                system.viewHistory();
                break;

            case 7:
                cout << "\nSystem closed.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}