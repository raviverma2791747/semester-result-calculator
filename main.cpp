#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<fstream>

using namespace std;

struct credit
{
    int total_subjects;
    int total_practical_subjects;
    string subjects[10];
    string practical_subjects[10];
    int credits[10];
    int practical_credits[10];
    int total_theory_credits;
    int total_practical_credits;
    int total_credit;
};

class record
{
    string name;
    string roll_no;
    int marks[10];
    int practical_marks[10];
    int pointers[10];
    int practical_pointers[10];
    credit c;
    float cgpa;

public:

    void input_data()
    {
        cout<<"======================================================\n";
        cout<<"                      INPUT                           \n";
        cout<<"======================================================\n";
        cout<<"Name        :";
        cin >> ws;
        getline(cin,name);
        cout<<"Roll Number :";
        getline(cin,roll_no);

        cout<<"\nTHEORY SUBJECTS\n\n";
        for(int i=0; i<c.total_subjects; i++)
        {
            cout<<left<<setw(11)<<c.subjects[i]<<" :";
            cin>>marks[i];
        }


        cout<<"\nPRACTICAL SUBJECTS\n\n";
        for(int i=0; i<c.total_practical_subjects; i++)
        {
            cout<<left<<setw(11)<<c.practical_subjects[i]<<" :";
            cin>>practical_marks[i];
        }

        pointer_calculator();
        cgpa_calculator();
    }

    void update(int seg=0)
    {
        cout<<"======================================================\n";
        cout<<"                      UPDATE                          \n";
        cout<<"======================================================\n";

        if(seg == 1)
        {
            cout<<"Name        :";
            cin >> ws;
            getline(cin,name);
        }
        else if(seg == 2)
        {
            cout<<"Roll Number :";
            getline(cin,roll_no);

        }
        else if(seg == 3)
        {
            cout<<"\nTHEORY SUBJECTS\n\n";
            for(int i=0; i<c.total_subjects; i++)
            {
                cout<<left<<setw(11)<<c.subjects[i]<<" :";
                cin>>marks[i];
            }
            pointer_calculator();
            cgpa_calculator();
        }
        else if(seg == 4)
        {
            cout<<"\nPRACTICAL SUBJECTS\n\n";
            for(int i=0; i<c.total_practical_subjects; i++)
            {
                cout<<left<<setw(11)<<c.practical_subjects[i]<<" :";
                cin>>practical_marks[i];
            }
            pointer_calculator();
            cgpa_calculator();
        }

    }

    char *grade(int mark=0,int t_h=0)
    {
        if(t_h == 0)
        {
            if(mark >= 90  && mark <=100)
            {
                return "A+";
            }
            else if(mark >= 80  && mark <=89)
            {
                return "A";
            }
            else if(mark >= 70  && mark <=79)
            {
                return "B+";
            }
            else if(mark >= 60  && mark <=69)
            {
                return "B";
            }
            else if(mark >= 50  && mark <=59)
            {
                return "C+";
            }
            else if(mark >= 40  && mark <=49)
            {
                return "C";
            }
            else if(mark >= 30  && mark <=39)
            {
                return "D+";
            }
            else if(mark >= 20  && mark <=29)
            {
                return "D";
            }
            else if(mark >= 10  && mark <=19)
            {
                return "E+";
            }
            else if(mark >= 0  && mark <=19)
            {
                return "E+";
            }
        }
        else
        {
            if(mark >= 45  && mark <=50)
            {
                return "A+";
            }
            else if(mark >= 40  && mark <=44)
            {
                return "A";
            }
            else if(mark >= 35  && mark <=39)
            {
                return "B+";
            }
            else if(mark >= 30  && mark <=34)
            {
                return "B";
            }
            else if(mark >= 25  && mark <=29)
            {
                return "C+";
            }
            else if(mark >= 20  && mark <=24)
            {
                return "C";
            }
            else if(mark >= 15  && mark <=19)
            {
                return "D+";
            }
            else if(mark >= 10  && mark <=14)
            {
                return "D";
            }
            else if(mark >= 5  && mark <=9)
            {
                return "E+";
            }
            else if(mark >= 0  && mark <=4)
            {
                return "E+";
            }
        }
    }


    void result()
    {
        char sv_or_nt;

        cout<<"=============================================================\n";
        cout<<"                           RESULT                            \n";
        cout<<"=============================================================\n\n";
        cout<<"Name :"<<name<<"\n";
        cout<<"Roll Number :"<<roll_no<<"\n\n";
        cout<<"+-----------------------------------------------------------+\n";
        cout<<"|                         THEORY SUBJECTS                   |\n";
        cout<<"|       +----------+----------+----------+----------+       |\n";
        cout<<"|       |"<<left<<setw(10)<<"Subject"<<"|"<<left<<setw(10)<<"Marks"<<"|"<<left<<setw(10)<<"Grade"<<"|"<<"          |       |\n";
        cout<<"|       +----------+----------+----------+----------+       |\n";
        for(int i=0; i<c.total_subjects; i++)
        {
            cout<<"|       |"<<left<<setw(10)<<c.subjects[i]<<"|"<<left<<setw(10)<<marks[i]<<"|"<<left<<setw(10)<<grade(marks[i])<<"|"<<"          |       |\n";
            cout<<"|       +----------+----------+----------+----------+       |\n";
        }
        cout<<"+-----------------------------------------------------------+\n\n";
        cout<<"+-----------------------------------------------------------+\n";
        cout<<"|                        PRACTICAL SUBJECTS                 |\n";
        cout<<"|       +----------+----------+----------+----------+       |\n";
        cout<<"|       |"<<left<<setw(10)<<"Subject"<<"|"<<left<<setw(10)<<"Marks"<<"|"<<left<<setw(10)<<"Grade"<<"|"<<"          |       |\n";
        cout<<"|       +----------+----------+----------+----------+       |\n";
        for(int i=0; i<c.total_practical_subjects; i++)
        {

            cout<<"|       |"<<left<<setw(10)<<c.practical_subjects[i]<<"|"<<left<<setw(10)<<practical_marks[i]<<"|"<<left<<setw(10)<<grade(practical_marks[i],1)<<"|"<<"          |       |\n";
            cout<<"|       +----------+----------+----------+----------+       |\n";
        }
        cout<<"+-----------------------------------------------------------+\n\n";
        cout<<"+--------------------+\n";
        cout<<"|  CGPA :"<<setw(5)<<cgpa<<"     |\n";
        cout<<"+--------------------+\n";

        cout<<"Do you want to save the result? Y/N\n";
        cin>>sv_or_nt;
        if(sv_or_nt == 'y' || 'Y')
        {
            ofstream saver;
            string file_name = roll_no;
            file_name.append(".txt");
            saver.open(file_name.c_str(),ios::out);
            saver<<"=============================================================\n";
            saver<<"                           RESULT                            \n";
            saver<<"=============================================================\n\n";
            saver<<"Name :"<<name<<"\n";
            saver<<"Roll Number :"<<roll_no<<"\n\n";
            saver<<"+-----------------------------------------------------------+\n";
            saver<<"|                         THEORY SUBJECTS                   |\n";
            saver<<"|       +----------+----------+----------+----------+       |\n";
            saver<<"|       |"<<left<<setw(10)<<"Subject"<<"|"<<left<<setw(10)<<"Marks"<<"|"<<left<<setw(10)<<"Grade"<<"|"<<"          |       |\n";
            saver<<"|       +----------+----------+----------+----------+       |\n";
            for(int i=0; i<c.total_subjects; i++)
            {
                saver<<"|       |"<<left<<setw(10)<<c.subjects[i]<<"|"<<left<<setw(10)<<marks[i]<<"|"<<left<<setw(10)<<grade(marks[i])<<"|"<<"          |       |\n";
                saver<<"|       +----------+----------+----------+----------+       |\n";
            }
            saver<<"+-----------------------------------------------------------+\n\n";
            saver<<"+-----------------------------------------------------------+\n";
            saver<<"|                        PRACTICAL SUBJECTS                 |\n";
            saver<<"|       +----------+----------+----------+----------+       |\n";
            saver<<"|       |"<<left<<setw(10)<<"Subject"<<"|"<<left<<setw(10)<<"Marks"<<"|"<<left<<setw(10)<<"Grade"<<"|"<<"          |       |\n";
            saver<<"|       +----------+----------+----------+----------+       |\n";
            for(int i=0; i<c.total_practical_subjects; i++)
            {

                saver<<"|       |"<<left<<setw(10)<<c.practical_subjects[i]<<"|"<<left<<setw(10)<<practical_marks[i]<<"|"<<left<<setw(10)<<grade(practical_marks[i],1)<<"|"<<"          |       |\n";
                saver<<"|       +----------+----------+----------+----------+       |\n";
            }
            saver<<"+-----------------------------------------------------------+\n\n";
            saver<<"+--------------------+\n";
            saver<<"|  CGPA :"<<setw(5)<<cgpa<<"     |\n";
            saver<<"+--------------------+\n";
            saver.close();
        }
    }


    void pointer_calculator()
    {
        for(int i=0; i<c.total_subjects; i++)
        {
            if(marks[i] >= 90  && marks[i] <=100)
            {
                pointers[i] = 10;
            }
            else if(marks[i] >= 80  && marks[i] <=89)
            {
                pointers[i] = 9;
            }
            else if(marks[i] >= 70  && marks[i] <=79)
            {
                pointers[i] = 8;
            }
            else if(marks[i] >= 60  && marks[i] <=69)
            {
                pointers[i] = 7;
            }
            else if(marks[i] >= 50  && marks[i] <=59)
            {
                pointers[i] = 6;
            }
            else if(marks[i] >= 40  && marks[i] <=49)
            {
                pointers[i] = 5;
            }
            else if(marks[i] >= 30  && marks[i] <=39)
            {
                pointers[i] = 4;
            }
            else if(marks[i]>= 20  && marks[i] <=29)
            {
                pointers[i] = 3;
            }
            else if(marks[i] >= 10  && marks[i] <=19)
            {
                pointers[i] = 2;
            }
            else if(marks[i] >= 0  && marks[i] <=19)
            {
                pointers[i] = 1;
            }
        }

        for(int i=0; i<c.total_practical_subjects; i++)
        {
            if(practical_marks[i] >= 90  && practical_marks[i] <=100)
            {
                practical_pointers[i] = 10;
            }
            else if(practical_marks[i] >= 80  && practical_marks[i] <=89)
            {
                practical_pointers[i] = 9;
            }
            else if(practical_marks[i] >= 70  && practical_marks[i] <=79)
            {
                practical_pointers[i] = 8;
            }
            else if(practical_marks[i] >= 60  && marks[i] <=69)
            {
                practical_pointers[i] = 7;
            }
            else if(practical_marks[i] >= 50  && practical_marks[i] <=59)
            {
                practical_pointers[i] = 6;
            }
            else if(practical_marks[i] >= 40  && practical_marks[i] <=49)
            {
                practical_pointers[i] = 5;
            }
            else if(practical_marks[i] >= 30  && practical_marks[i] <=39)
            {
                practical_pointers[i] = 4;
            }
            else if(practical_marks[i]>= 20  && practical_marks[i] <=29)
            {
                practical_pointers[i] = 3;
            }
            else if(practical_marks[i] >= 10  && practical_marks[i] <=19)
            {
                practical_pointers[i] = 2;
            }
            else if(practical_marks[i] >= 0  && practical_marks[i] <=19)
            {
                practical_pointers[i] = 1;
            }
        }
    }

    void cgpa_calculator()
    {
        cgpa = 0;
        for(int i=0; i<c.total_subjects; i++)
        {
            cgpa = cgpa + pointers[i]*c.credits[i];
        }
        for(int i=0; i<c.total_practical_subjects; i++)
        {
            cgpa = cgpa + practical_pointers[i]*c.practical_credits[i];
        }
        cgpa = cgpa/c.total_theory_credits;
    }

    void credit_feed(credit temp)
    {
        c = temp;
    }

    string ret_roll()
    {
        return roll_no;
    }
} r[15];

int main()
{
    credit k;
    k.total_theory_credits =21;
    k.total_practical_credits =2;
    k.total_credit = 6;
    k.total_subjects=6;
    k.total_practical_subjects=2;
    k.practical_credits[0] = 1;
    k.practical_credits[1] = 1;
    k.credits[0] = 4;
    k.credits[1] = 4;
    k.credits[2] = 4;
    k.credits[3] = 4;
    k.credits[4] = 2;
    k.credits[5] = 3;
    k.subjects[0] = "ICSE";
    k.subjects[1] = "MATHS";
    k.subjects[2] = "PHYSICS";
    k.subjects[3] = "C";
    k.subjects[4] = "ETHICS";
    k.subjects[5] = "EVS";
    k.practical_subjects[0] = "PHYSICS";
    k.practical_subjects[1] = "C";
    ifstream fin;
    int choice = 0;
    int total_count = 0;
    fin.open("count.txt",ios::in);
    fin>>total_count;
    cout<<total_count;
    fin.close();
    if(total_count > 0)
    {
        ifstream inp;
        inp.open("data.txt",ios::in);
        for(int i=0; i<=total_count; i++)
        {
            inp.read((char*) &r[i],sizeof(r[i]));
        }
        inp.close();
    }
    ofstream fout,fc;
    string roll;
    int flag=0;
    do
    {
        system("cls");
        cout<<"=============================================================\n";
        cout<<"                           MENU                              \n";
        cout<<"=============================================================\n\n";
        cout<<"[1]Add Record\n";
        cout<<"[2]Remove Record\n";
        cout<<"[3]Update Record\n";
        cout<<"[4]Display Record\n";
        cout<<"[5]Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            total_count = total_count + 1;
            fc.open("count.txt",ios::out);
            fc<<total_count;
            fc.close();
            r[total_count].credit_feed(k);
            r[total_count].input_data();
            fout.open("data.txt",ios::out|ios::app);
            fout.write((char*) &r[total_count], sizeof(r[total_count]));
            break;
        case 2:
            cout<<"FEATURE NOT AVAILABLE!\n";
            break;
        case 3:
            cout<<"Enter the Roll number to display the record\n";
            cin>>roll;
            for(int i=0; i<=total_count; i++)
            {
                if(roll == r[i].ret_roll())
                {
                    int temp_c;
                    cout<<"What do you want to update?\n";
                    cout<<"[1]Name\n";
                    cout<<"[2]Roll Number\n";
                    cout<<"[3]Theory Marks\n";
                    cout<<"[4]Practical Marks\n";
                    cout<<"[5]Exit\n";
                    cin>>temp_c;
                    if(temp_c >0 && temp_c <5)
                    {
                        r[i].update(temp_c);
                    }
                    flag = 1;
                }
            }
            if(flag==0)
            {
                cout<<"NO RECORDS FOUND!\n";
            }
            break;
            break;
        case 4:
            cout<<"Enter the Roll number to display the record\n";
            cin>>roll;
            for(int i=0; i<=total_count; i++)
            {
                if(roll == r[i].ret_roll())
                {
                    r[i].result();
                    flag = 1;
                }
            }
            if(flag==0)
            {
                cout<<"NO RECORDS FOUND!\n";
            }
            break;
        case 5:
            cout<<"EXITING PROGRAM!\n";
            system("pause");
            exit(0);
            break;
        default:
            cout<<"INVALID CHOICE! TRY AGAIN!\n";
        }
        system("pause");
    }
    while(choice != 5);
    fout.close();
    return 0;
}
