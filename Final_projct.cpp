//-------------->>   STAFF MANAGEMENT SYSTEM <<-----------------
/*our application will store the details of all the staffs working in a hospital         ||
there name, id, contact no, age, gender and all that                                     ||
Will show the option in the program menu to select                                       ||
print full list, input data, print by age, print by gender and increase data list size   ||
PROGRESS - it is now completed and 100% work is done.                                    ||
*/                                                                                       //
//=======================================================================================||
#include <iostream>
#include <fstream> //for file handling

using namespace std;
class staff_info //base class
{
	protected:
		staff_info() //constructor called of base class.
		{
			cout<<"\n Hello! Welcome to our staff Management System.... Hope your journey will be without errors ";
			
		}
		//=================================================================================================================================||
		//all the data members are private so that we can hide this all information from the outside world/                                ||
		//even the functions are also private                                                                                              ||
		
		//encapsulation is taking place from line 29-210 because all the data members and member functions are related and all are private ||
		//So, this thing is called as data binding and we are hiding this from the out side world.                                         ||
		
		//and we are using single inheritance                                                                                              ||
		//all the data members declared here as private====================================================================================||
	private:
		int countPersons = 0;
		int PERSONS_LIMIT = 10;                                       
		int count50plus =0;
		int lessthen50=0;
		int malecount=0;
		int femalcount=0;
		int limit, error, error1, error2;
		int n = 0;
		char position;
		struct st
		{
			int Id, Age;                            
			string Name;
			char Dob[8];
			char Position[30];
			char Gender;
			string contact_no;
			string pos;
		}s[20];	

		//here all the functions are private just to hide the details and implementation from the outside world.
	
		void input_staff()                                      	//to take the data for a new staff from user                                      
		{
			if(countPersons<PERSONS_LIMIT)                          //condition that it will run untill the countpersons will be grater than PERSONS_LIMIT
			{
				cout<<"\n So dear customer, how many staff's detail you want to enter: ";
				cin>>n;
				for(int i = 0; i < n; ++i)
				{
			        s[i].Id = i+1;
			        cout << "\n Kindly enter the details for staff with id: " << s[i].Id << ", " << endl;
			
			        cout << "\n Enter name (FIRSTNAME_MIDDLENAME_LASTNAME): ";
			        getline(cin.ignore(), s[i].Name);
			        
					do                                              //exception handling
					{
						try                                         //using try block to check error;
						{
				        cout << "\n Enter Age: ";
				        cin >> s[i].Age;
						if(!(s[i].Age>=18 && s[i].Age<=55))     //checking that age entered is valid or not;
						{
							throw(s[i].Age);                    //using throw block to transfer error to catch block;
						}
						error=0;                                //if all the conditions are false then value of error variable is 0
						}
						catch(int e)
						{
							cout<<"\n if entered age is less than 18 - STOP CHILD LABOUR and enered age is more than 55 than TIME TO RETIRE...."; //Showing error;
							error=1;                            //Changing value of variable to retake input;
						}
					}while(error);                                  //it takes input until all inputs are valid;
					cout<<"\n Age saved.. please move to next...";
					
					if(s[i].Age>50)                             //checking age greate than 50
						count50plus++;
					else
						lessthen50++;
					
					cout<<"\n Enter DOB (dd-mm-yy): ";               //entering date of birth
					cin>> s[i].Dob;
					
					cout<<"\n Enter Gender (M/F): ";                 //entering the gender
					cin>> s[i].Gender;
				
					if((s[i].Gender=='M') || (s[i].Gender=='m')) //checking of male
						malecount++;
					else                                        //checking of female
						femalcount++;
						
					do{                                              //checking for contact number of staff entered by the user
						try{
							cout<<"\n Enter Contact number: ";
							cin>> s[i].contact_no;
							if(s[i].contact_no.length() != 10)        //checking length of entered contact number
								throw(s[i].contact_no);
							error1 = 0;
							}
							
						catch(string g)
						{
							cout<<"\n Kindly input valid Contact number, this is INDIA not USA...."; //Showing error;
							error1=1;                             //Changing value of variable to retake input;							
						}
					}while(error1);
					cout<<"\n Contact and personal deatils saved... you can move further. ";
					
					countPersons++;                              
				}
			}
			else
			{
				data_list();                                     //to increase the storage of data list
			}	
	}

		
	void print_list()                                        //to print the list of the staff when press 2
	{
		cout<<"\n **** **** ```````````Printing All Records````````````` **** ****";
	    for(int i = 0; i < n; ++i)
	    {
	        cout <<"\n Id: " << i+1;
	        cout <<"\t Name: " << s[i].Name;
	        cout <<"\t Age " << s[i].Age;
			cout<<"\t DOB : "<<s[i].Dob;
			cout<<"\t Gender : "<<s[i].Gender;
			cout<<"\t Contact number : "<<s[i].contact_no; 
	    }
		cout<<"\n total number of persons : "<<countPersons<<endl;   		
	}
		
	//from here plymorphsm is starting like the below two functions have same name but the signature is different for both
	//the arguements passed in this is int type. and will print the list age wise.
	void printbycategory(int a)	                              //to print the list of the staff according to age 
	{
		cout<<"\n **** **** `````````Printing All Records by Age``````````` **** ****";  
		cout<<"\nList of people who are less than 50....\n";
		for(int i = 0; i < n; ++i)
		{
			if (s[i].Age < 50)                                //will print the list of staff who are less than50
			{
		        cout <<"\n Id: " << i+1;
		        cout <<"\t Name: " << s[i].Name;
		        cout <<"\t Age " << s[i].Age;
				cout<<"\t DOB : "<<s[i].Dob;
				cout<<"\t Gender : "<<s[i].Gender;
				cout<<"\t Contact number : "<<s[i].contact_no; 					
			}
		}
		cout<<"\nList of people who are more than 50....\n";
		for(int i = 0; i < n; ++i)
		{
			if(s[i].Age > 50)                                 //will print the list of staff who are less than50
			{
		        cout <<"\n Id: " << i+1;
		        cout <<"\t Name: " << s[i].Name;
		        cout <<"\t Age " << s[i].Age;
				cout<<"\t DOB : "<<s[i].Dob;
				cout<<"\t Gender : "<<s[i].Gender;
				cout<<"\t Contact number : "<<s[i].contact_no; 					
			}
		}
		cout<<"\n Persons more than 50 : "<<count50plus;
		cout<<"\n Persons less than 50 : "<<lessthen50;
	}
		
	//here we are passng char type arguement so that this make the signature different from the above function
	//and both functions are doing different work one is printing age wise and other is giving gender count.
	void printbycategory(char a, char b)  //this function will tell the male and female counts in the staff list and will show accordingly
	{
		cout<<"\n **** **** ``````````Printing All Records by Gender Count`````````` **** ****";  
		cout<<"\nList of people who are male....\n";
		for(int i = 0; i < n; ++i)
		{
			if (s[i].Gender == 'm')                           //will print the list of males
			{
		        cout <<"\n Id: " << i+1;
		        cout <<"\t Name: " << s[i].Name;
		        cout <<"\t Age " << s[i].Age;
				cout<<"\t DOB : "<<s[i].Dob;
				cout<<"\t Gender : "<<s[i].Gender;
				cout<<"\t Contact number : "<<s[i].contact_no; 					
			}
		}
		cout<<"\nList of people who are female....\n";
		for(int i = 0; i < n; ++i)
		{
			if(s[i].Gender == 'f')                         //will print the list of females
			{
		        cout <<"\n Id: " << i+1;
		        cout <<"\t Name: " << s[i].Name;
		        cout <<"\t Age " << s[i].Age;
				cout<<"\t DOB : "<<s[i].Dob;
				cout<<"\t Gender : "<<s[i].Gender;
				cout<<"\t Contact number : "<<s[i].contact_no; 					
			}
		}
		cout<<"\n Number of Male : "<< malecount;
		cout<<"\n Number of Female : "<< femalcount;
	}
	void assign_shift()                                   //to display and assign the shift 
	{
		cout<<"Here you can see the available duties for the staff:";
		string data;
		//open file
		ifstream obj;
		obj.open("position.txt");  //calling the text file 
		while(getline(obj,data))
		{
			cout<<"\n"<<data; //displaying all the available duties for the staff
		}
		obj.close();
	}
	void shift()
	{
		assign_shift();
		int id, input;
		string position;
		cout<<"\nHere are the list of staffs: ";
	    for(int i = 0; i < n; ++i) //displaying the id and name from the details so that user can see to whom he/she want to assign
	    {
	        cout <<"\n Id: " << i+1;
	        cout <<"\t Name: " << s[i].Name;
	    }
	    cout<<"\nFor how many staff you want to assign the shift: ";
	    cin>>input; //taking input from the user about how many shifts
	    for(int j = 0; j<input; j++)
	    {
		    cout<<"\nEnter Id of the staff you want to assign shift, the shift name and the time:  ";
		    cin>>id;
		    getline(cin.ignore(),position);
			for(int i = 0; i<n; i++)
			{
				if (s[i].Id==id)
				{
					s[i].pos=position;
					cout<<"The shift assigned for staff id "<<s[i].Id<<" is "<<s[i].pos; //will display the entered shift and time to the assigned id
				}
			}
		}
	}
	
	protected:	
		void data_list()                                          //function which follows operator overloading
		{
			staff_info am;                                        //object of class
			cout<<"\n The limit has exceeded, to how much you want to increase the limit: ";
			cin>>limit;                                           //taling user input to increase the limit
			am+limit;                                             //calling the operator
		}
		
		//the function which do operator overloading
		//using binay overloading and two operands/
		void operator+(int limit)                                 //passing the second operand in the argument
		{
			PERSONS_LIMIT += limit;                               //update the PERSONS_LIMIT by user input
			cout<<"\n The new limit is : "<<PERSONS_LIMIT<< " Kindly proceed... ";         //displaying the new llimit
		}

		//from line 103-118 we are calling the above 4 functions in the new functions which is protected and can be accessed in the derived class
		//and the below 5 methods are working as an interface
		void input_d()
		{
			input_staff();
		}
		void print_staff()
		{
			print_list();
		}
		void print_age()
		{
			printbycategory(2);
		}
		void print_gender()
		{
			printbycategory('M', 'F');
		}
		void staff_shift()
		{
			shift();
		}
		
		//destructor of base class called....
		~staff_info()
		{
			cout<<"\nThank you.... we hope that you experinced well while using this application.... ";	
		}		
};
//single inheritance - derived class, calling the base class
class shift: public staff_info
{
	public:
		//constructor of derived class- 
		shift()
		{
			cout<<"\n STAFF MANAGEMENT SYSTEM ";
		}
				
		//here I want to display these options again and again that's why I'm using while loop here.
		void display()                                          //public function so that we can access it in the main function and displaying all the functions
		{
			int choice = -1;                                    //initialised the condition for usng the while loop
			while(choice!=0)
			 {
				  cout<<"\n\n ============  ______PROGRAM MENU______ =============";
				  cout<<"\n 1 Input Records ";
				  cout<<"\n 2 Print All Records";
				  cout<<"\n 3 Print by Age";
				  cout<<"\n 4 Print by gender count";
				  cout<<"\n 5 Increase the data list memory";
				  cout<<"\n 6 Print the available duties for staff";
				  cout<<"\n 0 to exit";
				  
				  cout<<"\n What you want to choose kindly enter according to it... waitng for your choice........: ";
				  cin>>choice;
					if(choice ==  1)
					{
						input_d();	
					}
					else if(choice ==  2)
					{
						print_staff();	
					}
					else if(choice ==  3)
					{
						print_age();	
					}
					else if(choice ==  4)
					{
						print_gender();	
					}
					else if(choice == 5)
					{
						data_list();
					}
					else if(choice == 6)
						staff_shift();
					else
					{
						cout<<"\n Entered choice is not valid. kindly enetr correct choice..";
					}
				}
		}
		//destructor of derived class - message displayed...
		~shift()
		{
			cout<<"\n Application closed... Visit again.. ";
		}
};
int main()//object of only the derived class and calling the last function of the derived class to optimise the main function.
{
	shift s; 
	s.display(); 
	return 0;
}
		
	
