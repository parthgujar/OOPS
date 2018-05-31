#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h>


using namespace std;

const string filename= "president.txt";

int main()
{
   string txt;				/*takes whole sentence as the STRING*/
   string dot=".";
   int lng;					/*points to the character in the STRING line*/
   lng=0;					/*initializing the pointer*/
   string s1,s2,s3,s4,s5;	/*stores the FIRST, MIDDLE and LAST names*/
   string sBirth,sDeath;	/*stores the BIRTH and DEATH year as STRING*/
   int count;				/*counts the NUMBER OF SPACES*/
   int age;					/*calculates the age*/
   double birth, death;		/*stores the DEATH and BIRTH year VALUES*/
   float totalage,aver_age;
   totalage=0;aver_age=0;
   string s6;
   string start,end;		/*stores the START and END years in OFFICE*/
   ifstream filein;			/*keeps an internal get position with the location to be read in next inout operation*/
   filein.open(filename.c_str(),ios::in);  /*opens the file*/

   if(filein.is_open())
   {
	   cout<<"First name  "<<"Middle name "<<"Last name   "<<"Born "<<"Died  "<<"Age  "<<"Start "<<"End   "<<"Party                 "<<endl;
	   cout<<"----------  "<<"----------- "<<"---------   "<<"---- "<<"----  "<<"---  "<<"----- "<<"----  "<<"-----                 "<<endl;
	   /*prints the format default*/
	   while(!filein.eof())				/*ENTERS the loop untill the end of file is reached*/
	   {
		   if (getline(filein,txt))		/*takes teh new line in to 'txt' string*/
			{
			   if(txt==dot)				/*terminates the loop if dot(.) is detected in the new line*/
		       {
				break;
		       }
		       lng=txt.length();		/*calculates the length of a line*/
		       char c[lng];
		       txt.copy(c,lng);			/*copies the */
		       lng=0;

/*stores the names of the PRESIDENTS*/


		       /*for storing the first name*/
		        while(c[lng]!=' ')
		        {
		        	s1+=c[lng];				/*stores the FIRST NAME(s1)*/
		        	lng++;
		        }
		        	count++;				/*count NUMBER OF SPACES*/


		        	/*for storing the middle name*/
		        if(c[lng]==' ')
		        {
		        	lng++;
		        if(c[lng]>=97 && c[lng]<=122)
		        {
		        	while(c[lng]!=' ')
		        	{
		        		s4+=c[lng];			/*stores the LAST NAME-1(s4)*/
		        		lng++;
		        	}
		        	s4=s4+" ";
		        	count++;
		        }
		        while(c[lng]!=' ')
		        {
		        	s2+=c[lng];			/*stores the MIDDLE NAME-1 (s2)*/
		        	lng++;
		        }
		        	count++;
		        }


		        /*for storing the middle nad last names*/
		        if(c[lng]==' ')
		        {
		        	lng++;
		        if(c[lng]=='(')
		        {
		        	s5=s2;				/*stores name as LAST NAME-2 (s5) if no MIDDLE NAME*/
		        	s2="";
		        	s3="";
		        }
		        else
		        {
		        while(c[lng]!=' ')
		        {
		        	s3+=c[lng];			/*stores the MIDDLE NAME-2 (s3) if there */
		        	lng++;
		        }
	        		count++;
		        }
		        }



		        /*for storing the multiple middle and last names*/
		        if(c[lng]==' ')
		        {
		        	lng++;
		        if(c[lng]=='(')
		        {
		        	s5=s3;
		        	s3="";
		        }
		        else
		        {
		        while(c[lng]!=' ')
		        {
		        	s5+=c[lng];
		        	lng++;
		        }
		        	count++;
		        	lng++;
		        }
		        }



/*this part stores the birth year and death year and thus calculates the age based on the data*/
		        if(c[lng]=='(')
		        {
		        	lng++;
		        	lng++;
		        	while(c[lng]>=48 && c[lng]<=57)
		        	{
		        		sBirth+=c[lng];				/* store the BIRTH YEAR */
		        		lng++;
		        	}
		        	birth=atof(sBirth.c_str());

		        	if (c[lng]==' ')
		        	{
		        		lng++;
		        		if(c[lng]==')')
		        		{
		        			age='\0';
		        			lng++;
		        		}
		        		if(c[lng]=='-')
		        		{
		        			lng++;
		        			lng++;
		        		while(c[lng]>=48 && c[lng]<=57)
		        		{
		        			sDeath+=c[lng];
		        			lng++;
		        		}
		        		death=atof(sDeath.c_str());

		        		lng++;
		        		if(c[lng]==')')
		        		{
		        			age=death-birth;
		        		}
		        		lng++;
		        		}
		        	}
		        }



/*this part stores the PARTY name, the PRESIDENT belonged to */
		        if(c[lng]==' ')
		        {
		        	lng++;
		        	while(c[lng]!=' ')
		        	{
		        		s6+=c[lng];
		        		lng++;
		        	}
		        }



/*this part stores the START and END year of the PRESIDENT in OFFICE*/
		        if(c[lng]==' ')
		        {
		        	lng++;
		        	while(c[lng]>=48 && c[lng]<=57)
		        	{
		        	start+=c[lng];
		        	lng++;
		        	}

		        	if(c[lng]==' ')
		        		lng++;
		        	if(c[lng]=='-')
		        		lng++;
		        	if(c[lng]==' ')
		        		lng++;
		        	while(c[lng]>=48 && c[lng]<=57)
		        	{
		        		end+=c[lng];
		        		lng++;
		        	}
		        	if(end=="")
		        	{
		        		end=start;
		        	}
		        }


		        /*prints the first name*/
		       cout<<setw(12)<<left<<s1;
		       s1="";

		       /*prints the middle name*/
		       cout<<setw(12)<<left<<s2+" "+s3;
		       s2="",s3="";

		       /*prints the last name*/
		       cout<<setw(12)<<left<<s4+s5;
		       s4="";s5="";

		       /*prints the BIRTH YEAR */
		       cout<<setw(5)<<left<<sBirth;
		       sBirth="";

		       /*prints the DEATH YEAR*/
		       cout<<setw(5)<<left<<sDeath;

		       /*prints the AGE of the PRESIDENT*/
		       if(sDeath=="")
		       {
		    	   cout<<setw(4)<<right<<""<<"  ";
		       }
		       else
		       {
			       cout<<setw(4)<<right<<age<<"  ";
			       totalage=totalage+age;
			       age=0;
		       }
		       sDeath="";

		       /*prints the START YEAR and END YEAR in the office*/
		       cout<<setw(5)<<right<<start<<" ";
		       start="";
		       if(end!=start)
		       {
		   	   cout<<setw(4)<<right<<end<<"  ";
		       end="";
		       }
		       else
		       {
		       end=start;
		   	   cout<<setw(4)<<right<<end<<"  ";
		   	   end="";
		   	   }

		       /*prints the PARTY name that PRESIDENT belonged to*/
		       cout<<setw(21)<<left<<s6;
		       s6="";

		       cout<<"\n";
			}
	   }
   }

   filein.close();
   aver_age=totalage/39;
   cout<<"\n"<<"Average age at death = "<<setprecision(3)<<aver_age;
    return 0;
}
