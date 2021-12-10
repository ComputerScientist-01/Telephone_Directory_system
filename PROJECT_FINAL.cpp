#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

class Telephone
{
    char f_name[20],l_name[20], phone_no[20], email[25];   
    
public:
    void disp();         //function to display the data

    void get();          //function to input the data
    
    void input_call();   //function to call the input data function   
    
    void display_call(); //function to call the display data function
    
    void search();       //function to search the data
    
    void del();          //function to delete the data
    
    void mod();          //function to modify the data
}c;//object of class Telephone is created as 'c' 
void Telephone::get() //function to input the data
{
    puts("\nEnter  first name :");
    gets(f_name);
    
    puts("\nEnter  last name :");
    gets(l_name);
    
    puts("\nEnter phone number:");
    gets(phone_no);
    
    puts("\nEnter  email address:");
    gets(email);  
}
void Telephone::disp() //function to display the data
{
    puts("\n first name :");
    puts(f_name);
    
    puts("\n last name :");
    puts(l_name);
    
    puts("\n phone number:");
    puts(phone_no);
    
    puts("\n email address:");
    puts(email);
}
void Telephone::input_call()
{
    ofstream ofile;
    ofile.open("Tele", ios::app);
    get(); //here the data is input
    ofile.write((char*)&c, sizeof(c)); //the function now appends the data
    ofile.close();
}
void Telephone::display_call()
{
    ifstream ifile;
    ifile.open("Tele");
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        disp(); //here the data is displayed
        ifile.read ((char*)&c, sizeof(c));
    }
    ifile.close();
}
void Telephone::search() //function to search the data
{
    char m[20];
    ifstream ifile("Tele");
    puts("Enter name of Person which has to be searched");
    gets(m);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        if (strcmpi(m, f_name)==0)
            disp();
            ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
}
void Telephone::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("Tele", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    puts("Enter the name of the Person whose records you want to delete");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        if (strcmpi(b, f_name))
            ofile.write((char*)&c, sizeof(c));
        ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("Tele");
    rename("new", "Tele");
}
void Telephone::mod()
{
    char d[20];
    int p;
    puts("\nEnter name of Person whose record you want to modify\n");
    gets(d);
    fstream f;
    f.open("Tele", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a=f.tellg();
    while(! f.eof())
    {
        if (!strcmpi(d, f_name))
        {
            puts("\nPress 1 to change  first name\nPress 2 to  change last name\nPress 3 to change phone_no \nPress 4 to change  email address");
            cin>>p;
            switch(p)
            {
            case 1:
                gets(f_name);
                break;
            case 2:
                gets(l_name);
                break;
            case 3:
                gets(phone_no);
                break;
            case 4:
                gets(email);
                break;
            }
            f.seekg(a-sizeof(c), ios::beg);
            f.write((char*)&c, sizeof(c));
        }
        f.read((char*)&c, sizeof(c));
        a=f.tellg();
    }
    f.close();
}
void main ()
{
    int ch;
    char choice;
    do
    {
    cout<<"\t      Telephone Directory System";
    cout<<"\n ********************************************";
    cout<<"\n\n *  1. View Telephone details                 *";
    cout<<"\n\n *  2. Add new record                         *";
    cout<<"\n\n *  3. Search a Telephone record              *";
    cout<<"\n\n *  4. Delete a Telephone record              *";
    cout<<"\n\n *  5. Modify a Telephone record              *";
    cout<<"\n ********************************************";
    cout<<"\n\n Enter your choice: ";
    cin>>ch;


    switch(ch)
    {
    case 1:

             c.display_call();
        break;
    case 2:

            c.input_call();

            break;
    case 3:
            c.search();
            break;
    case 4:
        c.del();
        break;
    case 5:
        c.mod();
        break;
    default:
        {
        cout<<"\nerror!";
        }
        break;
    }
    cout<<"\ncontinue? (y/n)\n";
    cin>>choice;
    }while(choice=='y');
    cout<<"\nGood bye";
}
