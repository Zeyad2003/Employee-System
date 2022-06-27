/*  Created in March 2021
 *  Author : Zeyad Nasef
 *  Employee System (Consol Application)
 *  Dr Mostafa Saad Projects
 */
#include <bits/stdc++.h>
using namespace std;
vector<tuple<string, int, int, char> > tp; // name, age, salary, gender

string nm;
int sl, ag;
char gg;


void Employee_System()
{
    while (true)
    {
        EnterChoice:
        int choice;
        cout << "\n******Welcome to your Employee system******\n" << "!!Please Enter number between [0 : 4]\n\n";
        cout << "To close employee system enter (0)\n";
        cout << "To add new employee enter (1)\n";
        cout << "To print all employees enter (2)\n";
        cout << "To delete range by age enter (3)\n";
        cout << "To update salaries by name enter (4)\n";
        cout << "To delete employee with name and salary enter (5)\n";
        cin >> choice;

        if(!(choice >= 0 && choice <= 5)){
            cout << "PLease Enter number between 1 : 5\n";
            goto EnterChoice;
        } else {
            if(choice == 1) {
                cout << "Enter employee name:";
                cin.ignore();
                getline(cin, nm);

                cout << "Enter age:";
                cin >> ag;

                cout << "Enter salary:";
                cin >> sl;

                cout << "Enter gender (M/F):";
                cin >> gg;

                tp.emplace_back(nm, ag, sl, gg);
            }
            else if(choice == 2) {
                cout << "\n*************************************\n";

                if(tp.empty()) cout << "!!There is no Employees!!\n*************************************\n";

                else {
                    for (int i = 0; i < tp.size(); i++) {
                        cout << "The name of employee (" << i + 1 << ") is : " << get<0>(tp[i]) << "\n";
                        cout << "The age of employee (" << i + 1 << ") is : " << get<1>(tp[i]) << "\n";
                        cout << "The salary of employee (" << i + 1 << ") is : " << get<2>(tp[i]) << "\n";
                        (get<3>(tp[i]) == 'M' || get<3>(tp[i]) == 'm') ? cout << "The gender of employee (" << i + 1 << ") is : Male" << "\n"
                                                                       :
                        cout << "The gender of employee (" << i + 1 << ") is : Female" << "\n";
                        cout << "*************************************\n";
                    }
                }

                int decision;
                cout << "If you want to do more operation enter (1)\n";
                cout << "If you want to exit the program enter (0)\n";
                cin >> decision;
                if(decision) goto EnterChoice;
                else goto close;
            }
            else if(choice == 3) {
                int start, end;
                cout << "\nEnter the start age:";
                cin >> start;
                cout << "Enter the end age:";
                cin >> end;

                for(int i = 0; i < tp.size(); i++){
                    if(get<1>(tp[i]) >= start && get<1>(tp[i]) <= end)
                        tp.erase(tp.begin() + i);
                }
                cout << "\n*********************\n!!Deleted Successfully!!\n*********************\n";
            }
            else if(choice == 4) {
                cout << "\nEnter the employee name to update his salary : ";
                string name;
                int salary;
                cin.ignore();
                getline(cin, name);
                cout << "Enter the new salary : ";
                cin >> salary;

                bool is_found = false;

                for(auto & i : tp){
                    if(get<0>(i) == name){
                        is_found = true;
                        get<2>(i) = salary;
                        break;
                    }
                }

                if(is_found)
                    cout << "\n!!Salary Updated Successfully!!\n";
                else
                    cout << "\nNo employee with this name! Make sure the name is correct\n";
            }
            else if (choice == 5){
                again:
                string name;
                int salary;
                bool isFound = false;
                cout << "\nEnter the employee name to delete : ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter the employee salary to delete : ";
                cin >> salary;

                for(int i = 0; i < tp.size(); i++){
                    if(get<0>(tp[i]) == name && get<2>(tp[i]) == salary){
                        isFound = true;
                        tp.erase(tp.begin() + i);
                        break;
                    }
                }
                if(!isFound) cout << "**************\nNo employee with this name and salary! Make sure the name and salary is correct\n**************\n";
                else cout << "**************\n!!Deleted Successfully!!\n**************\n";
                cout << "\nIf you want to do retry operation enter (1)\n";
                cout << "If you want to exit the program enter (0)\n";
                cout << "If you want to do more operation press any other number\n";
                int decision; cin >> decision;
                if(!decision) goto close;
                else if(decision == 1) goto again;
                else goto EnterChoice;
            }
            else {
                close:
                cout << "\nThank you for using Employee system program - Wish you good day..\n";
                break;
            }
        }
    }
}
int main() {
    Employee_System();
}