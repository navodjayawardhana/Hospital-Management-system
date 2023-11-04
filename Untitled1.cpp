#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include "conio.h"
int count;
using namespace std;
class user
{
public:
    string id;
    string name;

};
class admin:public virtual user
{

    public:
    string username;
    string password;
    friend admin login2(admin);
    virtual void user_login();
	virtual void hospitleinformation();   
};


class doctor:public virtual user,public admin
{
	public:
	void user_login();
	friend doctor login3(doctor);
};

class patient:public virtual user,public admin
{
    public:
        void register1();
        friend patient login1(patient);
        void user_login();
        bool compare(string);
        bool com(string);
};


void patient:: register1()                                                   //PATIENT REJISTATION
    {
     fstream file,fhandle1;
     string pname, padd, pid,city,Blood,email,gender,contactno,name,DOB,age;

	cout<<"* * * * * * * * * * GETTING PATIENT DETAILS * * * * * * * * * *"<<endl;
	cout << "\n\n\nnpatient ID : ";cin >> pid;
	cout << "\npatient Name : ";cin >> pname;
	cout << "\nPatient Address : ";cin >> padd;
	cout<<"\nEnter city : ";cin>>city;
    cout<<"\nEnter Blood Group: ";cin>>Blood;
    cout<<"\nEnter email address : ";cin>>email;
    cout<<"\nEnter your DOB :";cin>>DOB;
    cout<<"\nEnter your Age :";cin>>age;
    cout<<"\nEnter your gender(M/F) : ";cin>>gender;
    cout<<"\nEnter contact no. : ";cin>>contactno;
    

    fhandle1.open("patient Details.csv",ios::app);
    fhandle1<<pid<<","<<pname<<","<<padd<<","<<city<<","<<Blood<<","<<email<<","<<DOB<<","<<age<<","<<gender<<","<<contactno<<","<<"\n";
    fhandle1.close();
    
	
    file.open("Patient details.txt",ios::out | ios::app);
	file << " " << pid << " "<< pname << " " << Blood<< " " << age << "\n";
	file.close();
}
   



//friend fuction declaration
patient login1(patient ob)
    {
     return ob;
    }

//friend fuction declaration
    admin login2(admin ob)
    {

    string username,password;
    cout<<"Enter Username : "<<endl;
    cin>>ob.username;

        cout<<"Enter Password : "<<endl;
        cin>>ob.password;
        return ob;

    }


       doctor login3(doctor ob)
    {

    string username,password;
    cout<<"Enter User name: ";
        cin>>ob.username;
        
    cout<<"\nEnter Password : ";
        cin>>ob.password;
        return ob;

    }
    
     doctor login4(doctor ob)                 //hospitle details casse
    {

    string username,password;
    cout<<"Press 'X' to exit ";
        cin>>ob.username;
        
    cout<<"Enter Password : ";
        
        return ob;

    }

//functions for patient login

void patient::user_login()                                             //PATIENT APPOIMENT
			{
				
				system("cls");
				
				{
				
				fstream file;
				
				string dname, did, dspe,dtime;
				cout << "\n\n\t\t\t Doctor Details";
			
			
				file.open("doctor details.txt", ios::in);
				if (!file)
					cout << "\n\nFile Opening Error!";
				else {
			
					cout << "\n\n\nDoctor ID\t\tName"
						<< "\t\t\tSpecification\t\tAvailable time "
							"\n\n";
					file >> did >> dname;
					file >> dspe >> dtime;
			
					while (!file.eof()) {
			
						cout << " " << did<< "\t\t\t" << dname<< "\t\t\t" << dspe<< "\t\t" << dtime<< "\n\n";
						file >> did >> dname;
					    file >> dspe >> dtime;
					}
			
					
			        cout << "\n\n\n\t\t\tAPPOIMENT";
					
					file.close();
					
				       }
			}
				
				{
				
				fstream file;
				string pname,pid,Blood,name,age,did,atime,gender;
			    cout << "\n\nEnter Doctor ID : ";cin >> did;
				cout << "\n\nEnter patient ID : ";cin >> pid;
				cout << "\npatient Name : ";cin >> pname;
				cout<<"\nEnter Blood Group: ";cin>>Blood;
			    cout<<"\nEnter your Age :";cin>>age;
			    cout<<"\nEnter your gender(M/F) : ";cin>>gender;
			    cout<<"\nEnter Appoiment Time ";cin>>atime;
			
				
				file.open("APPOIMENT.txt",ios::out | ios::app);
				file << " " <<""<<did<<" "<< pid << " "<< pname << " " << Blood<< " " << age <<" "<<atime<< "\n";
				file.close();
			    }
			}



void doctor::user_login()
    {
        int flag=0;
        string pname,did,pass;
            fstream fhandle10;
            fhandle10.open("doctor log in detail.csv",ios::in);
            while(fhandle10)
            {
                getline(fhandle10,did,',');
                getline(fhandle10,pass,'\n');
                if(username.compare(did)==0 && password.compare(pass)==0 )
                {
                    flag=1;
                    break;
                }
                else
                continue;
            }
            if(flag==0)
            {
                cout<<"Login Unsuccessful"<<endl;
            }
            else
            {
                  system("cls");
                        cout<<"                     ##################   Doctor Page      ##################\n\n\n"<<endl;
						cout<<"\n\n1. View Appoiment details"<<endl;
                        cout<<"\n2. Logout account"<<endl;
                        int choice;
                        cout<<"\n\nEnter your choice";
                        cin>>choice;
                        if(choice==1)
                        {
								system("cls");
								fstream file;
								int no_copy;
								string pname,pid,Blood,name,age,did,atime,gender;
								cout << "\n\n\t\t\t\t\t Patient Appoiment";
							
								// Open the file in input mode
								file.open("APPOIMENT.txt", ios::in);
								if (!file)
									cout << "\n\nFile Opening Error!";
								else {
							
									cout << "\n\n\nDoctor ID\t\tPatient ID\t\tPatient Name"
										<< "\t\tBlood\t\tAGE\t\tAPP Time "
											"\n\n";
									file >> did >> pid>>pname>>Blood;
									file >> age >> atime;
							
									while (!file.eof()) {
							
										cout << " " <<""<<did<<"\t\t\t "<< pid << " \t\t\t "<< pname << "\t\t\t " << Blood<< " \t\t" << age <<"\t\t "<<atime<< "\n";
										file >> did >> pid>>pname;
										file >> Blood >> age>>atime;
									}
										
							
									system("pause");
							
									// Close the file
									file.close();
								}
							}
                            
                        
                      
            }



    }


void admin::user_login()
            {
                string pname;
                if((username=="admin") && (password=="1234"))
                {
                    cout<<"admin login succesful"<<endl;

                    
                    {
                        system("cls");
                        cout<<"                     ##################   ADMINISTRATION      ##################\n\n\n"<<endl;
                        cout<<"1. Patient Details"<<endl;
                        cout<<"\n\n 2. View Doctor Details"<<endl;
                        cout<<"\n\n 3. Add Doctor"<<endl;
						cout<<"\n\n 4. Logout account"<<endl;
                        int choice;
                        cout<<"\n\n Enter your choice"<<endl;
                        cin>>choice;
                        
                        if(choice==1)
                        {
								system("cls");
								fstream file;
								int no_copy;
								string pname, pid, Blood,age;
								cout << "\n\n\t\t\t\t\tAll Patient";
							
								// Open the file in input mode
								file.open("Patient details.txt", ios::in);
								if (!file)
									cout << "\n\nFile Opening Error!";
								else {
							
									cout << "\n\n\nPatient ID\t\tName"
										<< "\t\tBlood\t\tAGE "
											"\n\n";
									file >> pid >> pname;
									file >> Blood >> age;
							
									while (!file.eof()) {
							
										cout << " " << pid<< "\t\t\t" << pname<< "\t\t" << Blood<< "\t\t" << age<< "\n\n";
										file >> pid >> pname;
										file >> Blood >> age;
									}
							
									system("pause");
							
									// Close the file
									file.close();
								}
							}
                        
                        else if(choice==2)
						       {
									system("cls");
									fstream file;
									string dname, did, dspeselist;
									cout << "\n\n\t\t\t\t\tDoctor";
								
									                                         // Open the file in input mode
									file.open("doctor details.txt", ios::in);
									if (!file)
										cout << "\n\nFile Opening Error!";
									else {
								
										cout << "\n\n\nDoctor Name"
											<< "\t\tDoctor ID\t\tSpecilice "
												"\n\n";
										file  >> dname;
										file >> did >> dspeselist;
								
										while (!file.eof()) {
								
											cout << dname
												<< "\t\t" << did
												<< "\t\t" << dspeselist
												<< "\n\n";
											file >> dname;
										    file >> did >> dspeselist;
										}
								
										system("pause");
								
										// Close the file
										file.close();
									}
								}

                        else if(choice==3)
                        {
                            
                            system("cls");
							fstream file;
							string dspeselist, dname, did,uname,dpassword,dtime ;
							cout << "\n\n\t\t\t\tADD DOCTOR";
							cout << "\n\n Create Doctor user name : ";
							cin >> uname;
							cout << "\n\n Create Doctor password : ";
							cin >> dpassword ;
							cout << "\n\n Doctor Name : ";
							cin >> dname;
							cout << "\n Doctor ID  : ";
							cin >> did;
							cout << "\n Doctor Speselist : ";
							cin >> dspeselist;
							cout << "\n Doctor Available time : ";
							cin >> dtime;
							
						
							                                    // Open file in append or
							                                  // output mode
						    file.open("doctor details.txt",
							ios::out | ios::app);
							file << " " << did << " "<< dname << " " << dspeselist <<" "<< dtime<< "\n";
							file.close();
	                        
	                        fstream fhandle10;
							    fhandle10.open("doctor log in detail.csv",ios::app);
							    fhandle10<<uname<<","<<dpassword<<"\n";
							    fhandle10.close();
                        }
                   
                       }
                      }
                    }
 void admin::hospitleinformation() 
 { }                 
               


int main()
{
   while(1)
   {
    cout<<"\n\t**********     WELLCOME SPIRE HOSPITAL AUTOMATED INFORMATION SYSTEM        **********"<<endl;
    cout<<"\n\n\t\t\t\t\t1.   PATIENT REGISTRATION"<<endl;
    cout<<"\n\t\t\t\t\t2.   APPOIMENT PATIENT "<<endl;
    cout<<"\n\t\t\t\t\t3.   ADMIN LOGIN"<<endl;
    cout<<"\n\t\t\t\t\t4.   DOCTOR LOGIN"<<endl;
    cout<<"\n\t\t\t\t\t5.   HOSPITLE INFORMATION "<<endl;
    cout<<"\n\t\t\t\t\t6.   EXIT"<<endl;
    char ch;
    cout<<"\n\n\n ENTER YOUR CHOICE - ";
    cin>>ch;
    system("cls");
    switch(ch)
    {
    case '1':
    {
          patient ob;
          ob.register1();
          cout<<"Any key to return";
            getch();
            system("cls");
          break;
    }

    case '2':
        {
            patient ob;
            ob=login1(ob);
            ob.user_login();
            cout<<"Any key to return";
            getch();
            system("cls");
            break;
        }
    case '3':
        {
            cout<<"                     ##################   ADMINISTRATION LOGIN     ##################\n\n\n"<<endl;
            admin ob1;
            ob1=login2(ob1);
            ob1.user_login();
            cout<<"Any key to return";
            
            system("cls");
            break;
        }

         case '4':
        {
            cout<<"                     ##################   DOCTOR LOGIN     ##################\n\n\n"<<endl;
            doctor ob1;

            ob1=login3(ob1);
            ob1.user_login();
            cout<<"Any key to return";
            system("cls");
           
            break;
        }
        
        case '5':
        {
          cout<<"----------------------------------------------------------\n\t\t\tE mail-Spiral@gmail.com"<<endl;
          cout<<"----------------------------------------------------------\n\t\t\tPhone num-+6487561234"<<endl;
          cout<<"----------------------------------------------------------\n\t\t\t\tLocation-Londun"<<endl;
          cout<<"-----------------------------------------------------------\n"<<endl;
            doctor ob1;

            ob1=login4(ob1);
            ob1.user_login();
            cout<<"Any key to return";
            
            system("cls");
            break;
        }
        
        case '6':
        {
            exit(0);
        }

    default:
        {
            break;
        }
    }


   }
return 0;
}
