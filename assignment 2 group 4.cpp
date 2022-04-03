#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;


class Employee											   // class employee
{
	protected:
		int jobType, id, exp, age, d, year, start_work_year;                               //declare necessary variable 
		string name, dob, contact_num, edu_level;
		float initial_salary, base_salary, rough_salary, nett_salary, epf;
		
	public:
		Employee()									//default constructor of employee : initialise the age , year and start work year
		{
			age = 0;
			year = 2022;
			start_work_year = 2022;
		}
		
		void setDetails()								//Mutator function : set data and user input for name, DOB,conctact number ,
		{										//education level and start work year
			cout << " Enter Job Type\t\t: ";
			cin >> jobType;
			cout << " Enter ID\t\t: ";
			cin >> id;
			
			cin.ignore();
			
			cout << " Enter Name\t\t: ";
			getline(cin,name);
			cout << " Enter D.O.B\t\t: ";
			getline(cin,dob);
			cout << " Enter Contact Number\t: ";
			getline(cin,contact_num);
			cout << " Enter Education Level\t: ";
			getline(cin,edu_level);		
			cout << " Enter First Work Year\t: ";
			cin >> start_work_year;	
		}
		
		void calAge()								//Mutator function  of calculation of Age
		{
			switch(dob.length())
			{
				case 8:
					age = year - stoi(dob.substr(4));
					break;
				
				case 9:
					age = year - stoi(dob.substr(5));
					break;
					
				case 10:
					age = year - stoi(dob.substr(6));
					break; 
			}
		}
		
		void calcExp()								//Mutator function  of calculation of Experience of years
		{
			exp = year - start_work_year;
		}
		
		void setJobType(int &set_jobType)					//Mutator function : set jobType
		{
			jobType = set_jobType;
		}
		
		void setId(int &set_id)							//Mutator function : set id
		{
			id = set_id;
		}
		
		void setName(string &set_name)						//Mutator function : set name
		{
			name = set_name;
		}
		
                void setAge(int &set_age)						//Mutator function : set age
		{
			age = set_age;
		}
		
		void setContact(string &set_contact)					//Mutator function : set contact number
		{
			contact_num = set_contact;
		}
		
		void setDOB(string &set_dob)						//Mutator function : set date of brith
		{
			dob = set_dob;
		}
		
		void setEdu(string &set_edu)					       //Mutator function : set education level
		{
			edu_level = set_edu;
		}
		
		void setExp(int &set_exp)						//Mutator function : set Experience of years
		{
			exp = set_exp;
		}
		
		void setStartWork(int &set_start_work)					//Mutator function : set start working date or date of entering the company
		{
			start_work_year = set_start_work;
		}
		
		void setYear(int &set_year)						//Mutator function : set working years
		{
			year = set_year;
		}
		
		void display()								//Mutator function :display the name, age , contact number , date of brith , education of level,
		{									//years of experience of years ,and start work year
			cout << " " << endl;
			cout << " Name\t\t: " << name << endl;
			cout << " Age\t\t: " << age << endl;
			cout << " Contact Number\t: " << contact_num << endl;
			cout << " D.O.B\t\t: " << dob << endl;
			cout << " Education Level: " << edu_level << endl;
			cout << " Years of Exp\t: " << exp << endl;
			cout << " Start Work Year: " << start_work_year << endl;
			cout << " " << endl;
		}
		
		int getJobType()							//Accessor function : get the job type (int)
		{
			return jobType;
		}
		
		int getId()								//Accessor function : get the id (int)
		{
			return id;	
		}
		
		int getAge()								//Accessor function : get the age (int)
		{
			return age;
		}
		
		string getName()							//Accessor function : get the name (string)
		{
			return name;
		}
		
		string getContact()							//Accessor function : get the contact number (string)
		{
			return contact_num;
		}		
		
		string getDOB()								//Accessor function : get the date of brith (int)
		{
			return dob;
		}
		
		string getEdu()								//Accessor function : get the education level (string)
		{
			return edu_level;
		}
		
		int getExp()								//Accessor function : getter job type
		{
			return exp;
		}
		
		int getStartWork()							//Accessor function : getter job type
		{
			return start_work_year;
		}
		
	friend void writeData(Employee *);						//friend function to write data of employee
};


class Executive : public Employee							// class executive which inherits publicly from class Employee
{
	private:
		float bonus;														
	
	public:
		Executive()								//default constructor : to initialise the data of salary ,base salary,rough salary ,net salary
		{									//epf socso and bonus
			initial_salary = 2000; 						// bachelor initial salary
 			d = 300;			   				// bachelor difference
			base_salary = 0;						//Mutator function :
			rough_salary = 0;						//Accessor function :
			nett_salary = 0;
			epf = 0;
			bonus = 0;	
		}	
		
		void calcBaseSalary()							//Mutator function : calculation of the salary in class Executive
		{
			
			if(edu_level.find("Diploma") == 0)
			{
				initial_salary = 1700;
				d = 200;
			}
			
			base_salary = initial_salary + ((exp)*(d));
		}
		
		void display_base_salary()						//Mutator function : display the base salary 
		{
			calcBaseSalary();
			cout << fixed;
			cout << " Base Salary\t: RM " << setprecision(2) << base_salary << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
		
		void setBonus()								//Mutator function : set bonus and let user enter the bonus
		{
			cout << " Enter Bonus\t: RM ";
			cin >> bonus;
		}
		
		void calcRoughSalary()							//Mutator function : calculation of rough salary
		{
			rough_salary = base_salary + bonus;
		}
		
		void EPF()								//Mutator function : calculation of EPF
		{
			epf = rough_salary*(0.09);
		}
		
		void calcNett()								//Mutator function : calculation of the net salary
		{
			nett_salary = rough_salary - epf;
		}
		
		float get_RoughSalary()							//Accessor function : get the rough salary
		{
			return rough_salary;
		}
		
		float get_BaseSalary()							//Accessor function : get the base salary
		{
			return base_salary;
		}
		
		float get_Epf()							//Accessor function : get the EPF 
		{
			return epf;
		}
		
		float get_NettSalary()							//Accessor function : get the net salary
		{
			return nett_salary;
		}
};


class BlueCollar : public Employee							//class BlueCollar which inherits publicly from class Employee
{
	private:
		float OT_rate, OT_pay;
		int OT_hours;
		
	public:
		BlueCollar()					//default constructor : to initiliase the data of salary ,base salary,rough salary ,net salary
		{						//Overtime of rate ,overtime of hours.
			OT_rate = 2.0;
			initial_salary = 1400;
			d = 50;
			base_salary = 0;
			nett_salary = 0;
			OT_hours = 0;
		}
		
		void calcBaseSalary()									//Mutator function : calculate the base salary
		{
			base_salary = initial_salary + ((exp)*(d));
		}
		
		void display_base_salary()								//Mutator function : display the base salary
		{
			calcBaseSalary();
			cout << fixed;
			cout << " Base Salary\t: RM " << setprecision(2) << base_salary << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
		
		void set_OtHours()					//Mutator function : set data of the overtime hours and user input for the overtime hours
		{
			cout << " Enter OT Hours\t: ";
			cin >> OT_hours;
		}
		
		void calcOtPay()									//Mutator function : calculate the overtime payment
		{
			OT_pay = (OT_hours*2)*(base_salary / (26*8));
		}
		
		void calcRoughSalary()									//Mutator function : calculate the rough salary
		{
			rough_salary = base_salary + OT_pay;
		}
		
		void EPF()										//Mutator function : calculate the epf 
		{
			epf = rough_salary*(0.09);
		}
		
		void calcNett()										//Mutator function : calculate the net salary
		{
			nett_salary = rough_salary - epf;
		}
		
		float get_RoughSalary()                                        				//Accessor function : get the data of rough salary
		{
			return rough_salary;
		}
		
		float get_BaseSalary()									//Accessor function : get the data of base salary
		{
			return base_salary;
		}
		
		float get_Epf()									//Accessor function : get the data of Epf 
		{
			return epf;
		}
		
		float get_NettSalary()									//Accessor function :get the data of net salary
		{
			return nett_salary;
		}
		
		float get_OtPay()									//Accessor function : get the data of overtime payment
		{
			return OT_pay;
		}
};


class Page												//class Page
{
	private:
		
		int menu, num_of_lines, compare_id, compare_year, compare_month; 		 	//declaration  neccessary variable
		int round,*fired_ID;
		char repeat_register;
		string which_file, line;
		
		Employee *Emp;										// create the object of Employee ,Executive and BlueCollar 
		Executive *Exec;									// and using the pointer.
		BlueCollar *Blue;
		
		// Troublesome parts !!!!
		int emp_jobType, emp_id, emp_exp, emp_age, emp_start_work;
		string emp_name, emp_dob, emp_contact, emp_edu;
		
	public:
		Page()											//default construtor of the Page : display the main page 
		{																
			repeat_register = 'Y';
			
			cout << " " << endl;
			cout << "\t\t TL3L Group 4 Sdn Bhd" << endl;                                                 
			cout << " ******************************************************" << endl;
			cout << " [1] Register New Employee(s) " << endl;
			cout << " [2] Search Employee Details " << endl;
			cout << " [3] Update Contact Number " << endl;
			cout << " [4] Update Employees' Details " << endl;
			cout << " [5] Calculate Employees' Salary " << endl;
			cout << " [6] Fire Employees' Salary " << endl;
			cout << " [7] End Program " << endl;
			cout << " ******************************************************" << endl;
		}
		
		void setMenu(int &m)    								// pass by reference using reference arguments
		{
			menu = m;
		}
		
		void display()										//display the choice from user 
		{
			if(menu == 1)									//when user enter choice 1 
			{
				cout << " " << endl;							//will display this section
				cout << "\t\t Register New Employee(s)" << endl;
				cout << " ******************************************************" << endl;
				
				cout << " [1] Executive" << endl;
				cout << " [2] Blue Collar" << endl;
				cout << " " << endl;
				
				do
				{
					Emp = new Employee;						//Using the DMA to allocate the array
					Emp->setDetails();						//calling the accessor funtion from class  Employee
					Emp->calAge();
					Emp->calcExp();
					
					writeData(Emp);							//Pass the class object to write data function
					
					delete Emp;							//delete object Employee
					
					cout << " " << endl;
					cout << " Continue Registering a New Employee ? : ";
					cin >> repeat_register;						//let user input their choice to continue of not
					cout << " " << endl;
					
				} while(repeat_register == 'Y');					//while user enter Y the programme will run again 
			}
			
			else if(menu == 2)								//when user enter the choice 2 will start this function
			{																		
				cout << " " << endl;
				cout << "\t\t Search Employee's Details" << endl;
				cout << " ******************************************************" << endl;
				cout << " Enter ID : ";	
				cin >> compare_id;							//let user enter Id number due to checking employee id 
				
				if(compare_id<2000)							//if employee id is 2000 
				{
					which_file = "Exe_Data.txt";					//assign the file name to 'which file'
				
					numOfLines(which_file);						//using the num of line to know how many line in the file
					Exec = new Executive[num_of_lines];				//using the DMA to allocate number of array
					
					ifstream myfile(which_file);					//open the file
					
					if(myfile.is_open())						//when file is open successfully
					{
						for(int i=0; i<num_of_lines; i++)                       //will using the for loop the read data in the file
						{
							myfile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
						    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
						    
						    if(compare_id == emp_id)			//when user input id number is same with the inside of the file id 
						    {				//that will pass the data to the accessor funtion by using calling accessor function
						    	Exec[i].setId(emp_id);								
						    	Exec[i].setName(emp_name);
						    	Exec[i].setAge(emp_age);
						    	Exec[i].setDOB(emp_dob);
						    	Exec[i].setContact(emp_contact);
						    	Exec[i].setEdu(emp_edu);
						    	Exec[i].setExp(emp_exp);
						    	Exec[i].setStartWork(emp_start_work);
						    	Exec[i].display();
						    	Exec[i].display_base_salary();
						    	
						    	compare_id = 0;
							}
						}
						delete [] Exec;							//delete the object of Executive with array
						myfile.close();							//closing the file and finish this pass	
					}
				
					else									//if can not open the file
					{
						cout << " " << endl;
						cout << " Unable to Open File " << endl;
					}
				}
				
				else										//if employee id is not 2000 
				{
					which_file = "Blue_Data.txt";
				
					numOfLines(which_file);
					Blue = new BlueCollar[num_of_lines];
					
					ifstream myfile(which_file);
					
					if(myfile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							myfile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
						    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
						    
						    if(compare_id == emp_id)
						    {
						    	Blue[i].setId(emp_id);
						    	Blue[i].setName(emp_name);
						    	Blue[i].setAge(emp_age);
						    	Blue[i].setDOB(emp_dob);
						    	Blue[i].setContact(emp_contact);
						    	Blue[i].setEdu(emp_edu);
						    	Blue[i].setExp(emp_exp);
						    	Blue[i].setStartWork(emp_start_work);
						    	Blue[i].display();
						    	Blue[i].display_base_salary();
						    	
						    	compare_id = 0;
							}
						}
						delete [] Blue;
						myfile.close();					
					}
				
					else
					{
						cout << " " << endl;
						cout << " Unable to Open File " << endl;
					}
				}
				
			}
			
			else if(menu == 3)									//when user choice the number 3
			{											//that will be updating the contact number
				cout << " " << endl;
				cout << "\t\t Update Contact Number" << endl;
				cout << " ******************************************************" << endl;
				cout << " Enter ID : ";
				cin >> compare_id;								//user input the id number due to compare
				cout << " " << endl;
				
				if(compare_id<2000)								//if id number is 2000
				{
					which_file = "Exe_Data.txt";						//the which file will be assigned by the "Exe_Data.txt"
				}
				else										//if id number is not 2000
				{
					which_file = "Blue_Data.txt";						//the which file will be assigned by the "Blue_Data.txt"
				}
				
				numOfLines(which_file);								//using the function of num of line to know how many line in the file
				Emp = new Employee[num_of_lines];
				
				// Read Data From a File and Store It
				ifstream infile(which_file);							//open the file
				
				if(infile.is_open())
				{
					for(int i=0; i<num_of_lines; i++)
					{
						infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 	//reading the file and store the data 
					    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
					    
					    Emp[i].setJobType(emp_jobType);
					    Emp[i].setId(emp_id);
				    	Emp[i].setName(emp_name);
				    	Emp[i].setAge(emp_age);
				    	Emp[i].setDOB(emp_dob);
				    	Emp[i].setContact(emp_contact);
				    	Emp[i].setEdu(emp_edu);
				    	Emp[i].setExp(emp_exp);
				    	Emp[i].setStartWork(emp_start_work);
				    	
				    	// Search Data
				    	if(compare_id == Emp[i].getId())					//if id number is same with the employee id
				    	{
				    		cout << " Name\t\t: " << Emp[i].getName() << endl;		//display the name ,age and contact number
				    		cout << " Age\t\t: " << Emp[i].getAge() << endl;
				    		cout << " Contact Number\t: " << Emp[i].getContact() << endl;
				    		
				    		cout << " " << endl;
				    		cout << " New Contact Number : ";
				    		cin >> emp_contact;						//let user enter the new contact number
				    		Emp[i].setContact(emp_contact);					//set the new contact number to the data or class
				    		
				    		cout << " " << endl;
				    		
				    		compare_id = 0;
						}
						// End -- Search Data
					}
				}
				
				infile.close();
				// End -- Read Data From a File and Store It
				
				
				// Write new update Data to the file
				ofstream outfile(which_file); 							//open the file
				
				if(outfile.is_open())								//if file is open 
				{
					for(int i=0; i<num_of_lines; i++)					//using the for loop to update data of employee
					{
						outfile <<Emp[i].getJobType() << " "<< Emp[i].getId() << " " << Emp[i].getName() << " "
						<< Emp[i].getDOB() << " " << Emp[i].getAge() << " " << Emp[i].getContact() << " " 
						<< Emp[i].getEdu() << " " << Emp[i].getExp() << " " << Emp[i].getStartWork() << "\n";
					}
				}
				
				outfile.close();								//closing the file
				delete [] Emp;									//delete the object employee 
				// End -- Write new update Data to the file
			}
			
			else if(menu == 4)								//when user enter the number 4 and this function will be run
			{	
				cout << " " << endl;
				cout << "\t\t Update Employees' Details" << endl;
				cout << " ******************************************************" << endl;
				cout << " This Program will automatically update the Employees'" << endl;
				cout << " based on their D.O.B and their Start Work Year." << endl;
				cout << " " << endl;
				cout << " Enter Year\t: ";
				cin >> compare_year;								//let user input the year
				
				round = 2;
				
				for(int j=0; j<round; j++)							//using the for loop the to know the job type
				{
					if(j==0)
					{
						which_file = "Exe_Data.txt";					//and to select the which file will be used
					}
					else if(j==1)
					{
						which_file = "Blue_Data.txt";
					}
					
					numOfLines(which_file);							//using the function to know how many line in the file
					Emp = new Employee[num_of_lines];
					ifstream infile(which_file);						//open the file 
					if(infile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)					
						{
							infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >>  //read data from the file
							emp_contact >> emp_edu >> emp_exp >> emp_start_work; 
							
							Emp[i].setJobType(emp_jobType);				//set data to the class employee
						    Emp[i].setId(emp_id);
					    	Emp[i].setName(emp_name);
					    	Emp[i].setAge(emp_age);
					    	Emp[i].setDOB(emp_dob);
					    	Emp[i].setContact(emp_contact);
					    	Emp[i].setEdu(emp_edu);
					    	Emp[i].setExp(emp_exp);
					    	Emp[i].setStartWork(emp_start_work);
					    	Emp[i].setYear(compare_year);
					    	Emp[i].calAge();
					    	Emp[i].calcExp();
						}
					}
					infile.close();								//closing the file
					
					
					ofstream outfile(which_file);						//open the file
					if(outfile.is_open())							//print out the data to the file
					{
						for(int i=0; i<num_of_lines; i++)
						{
							outfile << Emp[i].getJobType() << " "<< Emp[i].getId() << " " << Emp[i].getName() << " "
							<< Emp[i].getDOB() << " " << Emp[i].getAge() << " " << Emp[i].getContact() << " " 
							<< Emp[i].getEdu() << " " << Emp[i].getExp() << " " << Emp[i].getStartWork() << "\n";
						}
					}		
					outfile.close();							//closing the file
					num_of_lines = 0;
					delete [] Emp;                                   			// delete the object of employee
				}
				
				cout << " " << endl;
				cout << " " << endl;
				cout << " Finish Update " << endl;											
				cout << " " << endl;
				cout << " " << endl;
			}
			
			else if(menu == 5)									//when user choice 5 in the main page
			{
				cout << " " << endl;
				cout << "\t\t Calculate Employees' Salary" << endl;
				cout << " ******************************************************" << endl;
				
				ofstream outfile("Salary.txt");							//open the file -> "Salary.txt"
				
				round = 2;
				
				for(int j=0; j<round; j++)          	//if j=0 the file name ->    "Exe_Data.txt" ,else  the file name    -> "Blue_Data.txt"                           
				{
					if(j==0)
					{
						num_of_lines = 0;
						
						which_file = "Exe_Data.txt";
						numOfLines(which_file);
						
						Exec = new Executive[num_of_lines];
						
						ifstream infile(which_file);                            //open file
						if(infile.is_open())
						{
							for(int i=0; i<num_of_lines; i++)
							{
								infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >>//read file 
								emp_contact >> emp_edu >> emp_exp >> emp_start_work;
								
								Exec[i].setJobType(emp_jobType);	//set data to the class employee
								Exec[i].setId(emp_id);
								Exec[i].setName(emp_name);
						    	Exec[i].setAge(emp_age);
						    	Exec[i].setExp(emp_exp);
								Exec[i].calcBaseSalary();

								cout << fixed;
								
								cout << " Job Type\t: " << Exec[i].getJobType() << endl;	//display the job type , id ,name and base salary
								cout << " ID\t\t: " << Exec[i].getId() << endl;
								cout << " Name\t\t: " << Exec[i].getName() << endl;
								cout << " Base Salary\t: RM" << setw(8) << setprecision(2) << Exec[i].get_BaseSalary() << endl;
								Exec[i].setBonus();						//calling the asseccer function 
								
								Exec[i].calcRoughSalary();
								Exec[i].EPF();
								Exec[i].calcNett();
								
								cout << " Rough Salary\t: RM" << setw(8) << setprecision(2) << Exec[i].get_RoughSalary() << endl; //display the rought salary , epf and net salary
								cout << " EPF Socso (9%)\t: RM" << setw(8) << setprecision(2) << Exec[i].get_Epf() << endl;
								cout << " Nett Salary\t: RM" << setw(8) << setprecision(2) << Exec[i].get_NettSalary() << endl;
								
								cout << " " << endl;
								cout << " " << endl;
							}
						}
						infile.close();					//closing the file
						
						if(outfile.is_open())				//write data into the file
						{
							for(int i=0; i<num_of_lines; i++)													
							{
								outfile << fixed;
								outfile << setw(3) << Exec[i].getJobType() << setw(6) << Exec[i].getId() 
										<< setw(10) << Exec[i].getName()
										<<setw(8) << setprecision(2) << "RM" << Exec[i].get_Epf()
									    << setw(10) << setprecision(2) << "RM" << Exec[i].get_NettSalary() << "\n"; 
							}
						}
						delete [] Exec;							//delete object of the executive
					}
					
					else
					{
						num_of_lines = 0;
						
						which_file = "Blue_Data.txt";
						numOfLines(which_file);
						
						Blue = new BlueCollar[num_of_lines];
						
						ifstream infile(which_file);					//open the file
						if(infile.is_open())
						{
							for(int i=0; i<num_of_lines; i++)
							{
								infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 	//read data from the file
								emp_contact >> emp_edu >> emp_exp >> emp_start_work;
								
								Blue[i].setJobType(emp_jobType);
								Blue[i].setId(emp_id);
								Blue[i].setName(emp_name);
								Blue[i].setAge(emp_age);
						    	Blue[i].setExp(emp_exp);
						    	Blue[i].calcBaseSalary();
						    	
						    	cout << fixed;
						    	
						    	cout << " Job Type\t: " << Blue[i].getJobType() << endl;										//display the job type , id ,name and base salary
								cout << " ID\t\t: " << Blue[i].getId() << endl;
								cout << " Name\t\t: " << Blue[i].getName() << endl;
								cout << " Base Salary\t: RM" << setw(8) << setprecision(2) << Blue[i].get_BaseSalary() << endl;
								Blue[i].set_OtHours();
								
								Blue[i].calcOtPay();				//calculation using the calling accessor function
								Blue[i].calcRoughSalary();
								Blue[i].EPF();
								Blue[i].calcNett();
								
								cout << " Total OT Pay\t: RM" << setw(8) << setprecision(2) << Blue[i].get_OtPay() << endl;							//display the data after calculation
								cout << " Rough Salary\t: RM" << setw(8) << setprecision(2) << Blue[i].get_RoughSalary() << endl;
								cout << " EPF Socso (9%)\t: RM" << setw(8) << setprecision(2) << Blue[i].get_Epf() << endl;
								cout << " Nett Salary\t: RM" << setw(8) << setprecision(2) << Blue[i].get_NettSalary() << endl;
								
								cout << " " << endl;
								cout << " " << endl;
							}
							
						}
						infile.close();							//closing the file
						
						if(outfile.is_open())						//open the file and write data into the file
						{
							for(int i=0; i<num_of_lines; i++)
							{
								outfile << fixed;
								outfile << setw(3) << Blue[i].getJobType() << setw(6) << Blue[i].getId() 
										<< setw(10) << Blue[i].getName()
										<<setw(8) << setprecision(2) << "RM" << Blue[i].get_Epf()
									    << setw(10) << setprecision(2) << "RM" << Blue[i].get_NettSalary() << "\n"; 
							}
						}
						delete [] Blue;					//delete the object
					}
				}
				outfile.close();						//closing the file
			}		
			
			else if(menu == 6)							//when user enter the value is 6
			{
				cout << " " << endl;
				cout << "\t\t Fire Employee(s)" << endl;
				cout << " ******************************************************" << endl;
				cout << " How many Employee to be Fired ? : ";
				cin >> round;							//user input due to looping
				cout << " " << endl;
				
				fired_ID = new int[round];					//using DMA to allocated array
				
				for(int j=0; j<round; j++)
				{
					cout << " # Fire --- " << j+1 << endl;
					cout << " Enter ID\t: ";
					cin >> fired_ID[j];
					
					if(fired_ID[j] < 2000)					//determine which file will be use
					{
						which_file = "Exe_Data.txt";
					}
					else
					{
						which_file = "Blue_Data.txt";
					}
					
					numOfLines(which_file);
					Emp = new Employee[num_of_lines];
					
					// Read Data From a File and Store It
					ifstream infile(which_file);
					
					if(infile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >>   //read data from the file
						    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
						    
						    Emp[i].setJobType(emp_jobType);
					    	Emp[i].setId(emp_id);
					    	Emp[i].setName(emp_name);
					    	Emp[i].setAge(emp_age);
					    	Emp[i].setDOB(emp_dob);
					    	Emp[i].setContact(emp_contact);
					    	Emp[i].setEdu(emp_edu);
					    	Emp[i].setExp(emp_exp);
					    	Emp[i].setStartWork(emp_start_work);
					    	
					    	if(fired_ID[j] == Emp[i].getId())					//when fire id same with the employee id
					    	{
					    		cout << " Name\t\t: " << Emp[i].getName() << endl;		//will display the name of employee
					    		
					    		cout << " " << endl;
							}
						}
					}
					infile.close();		//closing the file
					
					ofstream outfile(which_file);
					
					if(outfile.is_open())								//write data to the file
					{
						for(int i=0; i<num_of_lines; i++)					
						{
							if(fired_ID[j] != Emp[i].getId())
							{
								outfile <<Emp[i].getJobType() << " "<< Emp[i].getId() << " " << Emp[i].getName() << " "
								<< Emp[i].getDOB() << " " << Emp[i].getAge() << " " << Emp[i].getContact() << " " 
								<< Emp[i].getEdu() << " " << Emp[i].getExp() << " " << Emp[i].getStartWork() << "\n";
							}
						}
					}
					num_of_lines = 0;
					outfile.close();
					delete [] Emp;
				}
				delete [] fired_ID;
			 }
			}
		
		
		void numOfLines(string which_file)				//this function is calcute how many line in the file due to the looping
		{
			ifstream myfile(which_file);
			
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					num_of_lines = num_of_lines + 1;
				}
				myfile.close();		
			}
			
			else 
			{
				cout << "Unable to open file"; 
				num_of_lines = 0;
			}
			
		}
};


void writeData(Employee *Emp)					//write data to the file 
{
	ofstream Exe_Data, Blue_Data;
	
	if(Emp->jobType == 1)
	{
		Exe_Data.open("Exe_Data.txt",std::ios_base::app); // append write in -- won't clear the previous one
		if(Exe_Data.is_open())
		{
			Exe_Data << Emp->jobType << " " << Emp->id << " " << Emp->name <<" " <<
						Emp->dob << " " << Emp->age << " " << Emp->contact_num << " " <<
						Emp->edu_level << " " << Emp->exp << " " << Emp->start_work_year << "\n";
			Exe_Data.close();
		}
		
		else
		{
			cout << " Unable to Open File " << endl;	
		}
	}
	else
	{
		Blue_Data.open("Blue_Data.txt",std::ios_base::app); // append write in -- won't clear the previous one
		if(Blue_Data.is_open())
		{
			Blue_Data << Emp->jobType << " " << Emp->id << " " << Emp->name <<" " <<
						Emp->dob << " " << Emp->age << " " << Emp->contact_num << " " <<
						Emp->edu_level << " " << Emp->exp << " " << Emp->start_work_year << "\n";
			Blue_Data.close();
		}
		
		else
		{
			cout << " Unable to Open File " << endl;	
		}
	}
}


int main()  
{
	Page *page;       								//declare the object of the Page,and display the consturctor (main page)
	
	string space;
	int menu_selection = 0;
	
	do											//do while loop 
	{
		page = new Page;
		
		cout << " Enter Menu Selection : ";
		cin >> menu_selection;								//let user to enter value of the main page
		
		system("cls");
		page->setMenu(menu_selection);							//passing the value the accessor function due to know user input
		page->display();
		
		
		if(menu_selection == 7)								//if user enter number 7
		{
			cout << " Thank you for using this Program"; 		
		}
		else										//if user enter number is not 7
		{
			cout << " Press Enter to the Home Page";
		}
		
		cin.ignore();
		getline(cin,space);
		
		system("cls");
		
		delete page;
			
	} while(menu_selection != 7);	
	
	
	return 0;
	//end of the programme
}
