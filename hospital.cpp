#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<fstream.h>

int usedPatNos[10];
int w[10] = {1,2,3,4,5,6,7,8,9,10} ;
int c=0;
int generate()
{  start:
   int id,i;
   id = rand();

  if(id<1000)
	id = id*10;
  else if(id>1000)
	id = id/10;

  for(i=0;i<10;i++)
   {
	 if(usedPatNos[i]==id)
	 goto start;
	  //generate();
   }

  usedPatNos[i]=id;
  return id;
}

int ward()
{ int wno=10;
  int i;
  for(i=c;i<10;i++)
   {
	 wno=w[i];
	 c++;
	 break;
   }
  return wno;
}

enum status{F,B};

// MISTAKE HERE : array indces reversed, [10][3] makes an array of 3 elements, each 10 elements long
char branch[][10] = {"PHY","PED","ENT","GYN","OPT","ORT","GNM","GNS","CRD","DER"};


//Doctor class-------------------------------------------------------------
//--------------------------------------------------------------------------

class Doctor{
 int DocCode;
 char name[50];
 char sex;
 int age;
 long int salary;

public:
 void setdocDetails();
 void DocDetails();
 void dispdocDetails();
 int getDocCode();
 void getdocDetails();
 void docCheckin();
 void docdisall();
};

void Doctor::docdisall()
{
  Doctor d;
  ifstream ifs;
  ifs.open("DoctorDetails.dat",ios::in|ios::binary);
  ifs.seekg(0);

  while(ifs.read((char*)&d,sizeof(d)))
  {
	  d.dispdocDetails();
	  cout<<endl;
     getch();
  }

  ifs.close();
}

void Doctor::setdocDetails()
{
  DocCode = rand();

  if(DocCode<1000)
	DocCode = DocCode*15;
  else if(DocCode>1000)
	DocCode = DocCode/15;

  cout<<"\nEnter Name : ";
  gets(name);

  cout<<"\nSex(M/F/O) : ";
  cin>>sex;

  cout<<"\nEnter age : ";
  cin>>age;

  salary=60000;
}

void Doctor::DocDetails()
{
  Doctor d;
  ofstream ofs;
  ofs.open("DoctorDetails.dat",ios::out,ios::binary);

  //ifstream ifs;
  //ifs.open

  char nxtdoc = 'Y';

  do
  {
	d.setdocDetails();
	ofs.write((char*)&d,sizeof(d));
	cout<<"\nEnter next Doctor? (Y/N)...";
		cin>>nxtdoc;
  }while(nxtdoc=='y'||nxtdoc=='Y');
  ofs.close();
}

void Doctor::dispdocDetails()
{
   clrscr();
   cout<<"********************************************"<<endl;
   cout<<"         GH Hospital Doctor Details        "<<endl;
   cout<<"********************************************"<<endl;

   cout<<"\nDoctor Code    : "<<DocCode<<endl;
   cout<<"Name             : "<<name<<endl;
   cout<<"Sex              : "<<sex<<endl;
   cout<<"Age              : "<<age<<endl;
   cout<<"Salary           : "<<salary<<endl;

   cout<<"---------------------"<<endl;
}

int Doctor::getDocCode()
{
  return DocCode;
}

void Doctor::getdocDetails()
{
  int f=1;
  Doctor d;
  ifstream ifs;
  ifs.open("DoctorDetails.dat",ios::in|ios::binary);
  int vDoc;
  cout<<"\nEnter Doctor Code : ";
  cin>>vDoc;
  ifs.seekg(0);

  while(!ifs.eof())
  {
   ifs.read((char*)&d,sizeof(d));
	if(vDoc==d.getDocCode())
	{
	  cout<<"\nDoctor record found.\n"<<endl;
	  d.dispdocDetails();
	  f=0;
	  break;
	}
  }
	if(f==1)
	  cout<<"\nDoctor not found.\n"<<endl;
   ifs.close();

}

void Doctor::docCheckin()
{
   Doctor d;
   char Temp[50];
   ifstream ifs;
   ifs.open("DoctorDetails.dat",ios::in|ios::binary);
   int ecode,f=1;
   cout<<"\nPlease enter your name : ";
   gets(Temp);
   cout<<"\nPlease enter your employee code : ";
   cin>>ecode;
   ifs.seekg(0);

  while(!ifs.eof())
  {
   ifs.read((char*)&d,sizeof(d));
	if(ecode==d.getDocCode())
	{
	  f=0;
	  break;
	}
  }
   if(f==0)
	cout<<"\nYou have been successfully checked in.";
   else
	cout<<"Incorrect Details";
   ifs.close();
   getch();
}

//Nurse class-------------------------------------------------------------
//--------------------------------------------------------------------------

class nurse {
 int NurCode;
 char name[50];
 char sex;
 int age;
 long int salary;

public:
 void setDetails();
 void NurDetails();
 void dispDetails();
 int getNurCode();
 void getDetails();
 void Checkin();
 void nurdisall();
};

void nurse::nurdisall()
{
  nurse n;
  ifstream ifs;
  ifs.open("NurseDetails.dat",ios::in|ios::binary);
  ifs.seekg(0);

  while(ifs.read((char*)&n,sizeof(n)))
  {
   n.dispDetails();
   cout<<endl;
   getch();
  }

   ifs.close();
}

void nurse::setDetails()
{
   NurCode = rand();

   if(NurCode<1000)
	NurCode = NurCode*5;
   else if(NurCode>1000)
	NurCode = NurCode/5;

   cout<<"\nEnter Name : ";
   gets(name);

   cout<<"\nSex(M/F/O) : ";
   cin>>sex;

   cout<<"\nEnter age : ";
   cin>>age;

   salary=35000;
}

void nurse::NurDetails()
{
  nurse n;;
  ofstream ofs;
  ofs.open("NurseDetails.dat",ios::app|ios::binary);
  char nxtnur='Y';

  do
  {
	n.setDetails();
	ofs.write((char*)&n,sizeof(n));
	cout<<"\nEnter next nurse? (Y/N)...";
		cin>>nxtnur;
  }while(nxtnur=='y'||nxtnur=='Y');
  ofs.close();
}

void nurse::dispDetails()
{
   clrscr();
   cout<<"********************************************"<<endl;
   cout<<"         GH Hospital Nurse Details        "<<endl;
   cout<<"********************************************"<<endl;

   cout<<"\nNurse Code   : "<<NurCode<<endl;
   cout<<"Name             : "<<name<<endl;
   cout<<"Sex              : "<<sex<<endl;
   cout<<"Age              : "<<age<<endl;
   cout<<"Salary           : "<<salary<<endl;

   cout<<"---------------------"<<endl;
}

int nurse::getNurCode()
{
  return NurCode;
}

void nurse::getDetails()
{
  int f=1;
  nurse n;
  ifstream ifs;
  ifs.open("NurseDetails.dat",ios::in|ios::binary);
  int vNur;
  cout<<"\nEnter Nurse Code : ";
  cin>>vNur;
  ifs.seekg(0);

  while(!ifs.eof())
  {
   ifs.read((char*)&n,sizeof(n));
	if(vNur==n.getNurCode())
	{
	  cout<<"\nNurse record found.\n"<<endl;
	  n.dispDetails();
	  f=0;
     break;
   }
  }
	if(f==1)
	  cout<<"\nNurse not found.\n"<<endl;
   ifs.close();
}

void nurse::Checkin()
{
   nurse n;
   char Temp[50];
   ifstream ifs;
   ifs.open("NurseDetails.dat",ios::in|ios::binary);
   int ecode,f=1;
   cout<<"\nPlease enter your name : ";
   gets(Temp);
   cout<<"\nPlease enter your employee code : ";
   cin>>ecode;
   ifs.seekg(0);

  while(!ifs.eof())
  {
   ifs.read((char*)&n,sizeof(n));
	if(ecode==n.getNurCode())
	{
	  f=0;
	  break;
	}
  }
   if(f==0)
	cout<<"\nYou have been successfully checked in.";
   else
	cout<<"Incorrect Details";
   ifs.close();
   getch();
}



//Patient class-------------------------------------------------------------
//------------------------------------------------------------------------------
class Patient{
 int patNo;
 char name[50];
 char sex;
 int age;
 char docConsult[5];
 int wardNo;
 char Emergency;
 char admit;
 int docref;
 int req;
 long int fee;

public:
 void setDetails(char);
 void PatDetails();
 void dispDetails();
 int getpatNo();
 int getadmit();
 void record();
 void getDetails();
 void emergency();
 void patModify();
 void Discharge();
 void disall();
};

void Patient::disall()
{
  Patient p;
  ifstream ifs;
  ifs.open("PantientDetails.dat",ios::in|ios::binary);
  ifs.seekg(0);

  while(ifs.read((char*)&p,sizeof(p)))
  {
   p.dispDetails();
   cout<<endl;
   getch();
  }
   ifs.close();
}

void Patient::setDetails(char mode)
{
  clrscr();
  cout<<"********************************************"<<endl;
  cout<<"         GH Hospital Patient Entry           "<<endl;
  cout<<"********************************************"<<endl;

  cout<<"\nEnter Name : ";
  gets(name);

  cout<<"\nSex(M/F/O) : ";
  cin>>sex;

  cout<<"\nEnter age : ";
  cin>>age;

  Emergency = 'N';
  clrscr();
  cout<<"********************************************"<<endl;
  cout<<"         GH Hospital Patient Entry           "<<endl;
  cout<<"********************************************"<<endl;
  cout<<"\nReqirement (Enter serial no.): \n\n 1. EMERGENCY"<<endl;
  cout<<" 2. Pediatrician"<<endl;
  cout<<" 3. ENT"<<endl;
  cout<<" 4. Orthopedic"<<endl;
  cout<<" 5. Opthalmologist"<<endl;
  cout<<" 6. General Medicine"<<endl;
  cout<<" 7. Gynecologist and Obstratitain"<<endl;
  cout<<" 8. Dermatologist"<<endl;
  cout<<" 9. General Surgery"<<endl;
  cout<<"10. Cardilogist\n"<<endl;

  cin>>req;

  switch(req){
	case 1:  emergency();
			docref=0;
		 break;
	case 2:  strcpy(docConsult,"PED");
			docref=101;
	   break;
	case 3:  strcpy(docConsult,"ENT");
			docref=102;
	   break;
	case 4:  strcpy(docConsult,"ORT");
			docref=103;
	   break;
	case 5:  strcpy(docConsult,"OPT");
			docref=104;
	   break;
	case 6:  strcpy(docConsult,"GNM");
			docref=105;
	   break;
	case 7:  strcpy(docConsult,"GYN");
			docref=106;
	   break;
	case 8:  strcpy(docConsult,"DER");
				docref=107;
	   break;
	case 9:  strcpy(docConsult,"GNS");
			docref=108;
	   break;
	case 10: strcpy(docConsult,"CRD");
			docref=109;
	   break;
  }

  if(mode=='N') {
   	if(c==10){
      	cout<<"Cannot admit patient. No rooms free"<<endl;
			admit='N';
   	}
  		else {
      	cout<<"\nAdmit patient? (Y/N)...";
			cin>>admit;
   	}

      if(admit=='Y'||admit=='y')
		{
		 	wardNo=ward();
		 	cout<<"Your ward number is "<<wardNo<<endl;
		}

		if(admit=='y'||admit=='Y')
	   {
     		fee=10000;
	 		cout<<"Charges for a ward are "<<fee<<"/Day";
      }
		else
      {
   		fee=1000;
	 		cout<<"The Fees is "<<fee;
    	}

  		patNo=generate();
		cout<<"\nThe staff will now take the patient to the concerned doctor.";
  }
  else if(mode=='M') {
      // Modify something else
  }
  cout<<"\nDoctor Reference code is "<<docref;
  cout<<"\n\nYour patient number is "<<patNo<<endl;
}

void Patient::PatDetails()
{
  Patient p;
  ofstream ofs;
  ofs.open("PantientDetails.dat", ios::binary|ios::app);
  char nxtpat='Y';

  do
  {
	p.setDetails('N');
	ofs.write((char*)&p,sizeof(p));
	cout<<"\nEnter next patient? (Y/N)...";
		cin>>nxtpat;
	  clrscr();
  }while(nxtpat=='y'||nxtpat=='Y');
  ofs.close();
}

void Patient::dispDetails()
{
   clrscr();
   cout<<"********************************************"<<endl;
   cout<<"         GH Hospital Patient Details        "<<endl;
   cout<<"********************************************"<<endl;

   cout<<"\nPatient Number   : "<<patNo<<endl;
   cout<<"Name             : "<<name<<endl;
   cout<<"Sex              : "<<sex<<endl;
   cout<<"Age              : "<<age<<endl;
   cout<<"Doctor Consulted : "<<docConsult<<endl;
   cout<<"Ward Number      : "<<wardNo<<endl;

   if(Emergency=='Y'||Emergency=='y')
	 cout<<"Emergency        : YES"<<endl;
   else if(Emergency=='N'||Emergency=='n')
	 cout<<"Emergency        : NO"<<endl;
   else
	 cout<<"Emergency        : N/A"<<endl;

   if(admit=='Y'||admit=='y')
	 cout<<"Admitted         : YES"<<endl;
   else if(admit=='N'||admit=='n')
	 cout<<"Admitted         : NO"<<endl;
   else
	 cout<<"Admitted         : N/A"<<endl;

   if(req==1)
	cout<<"Doc Reference     : N/A"<<endl;
   else
	cout<<"Doc reference     : "<<docref;

   cout<<"\nFees             : "<<fee<<endl;

   cout<<"---------------------"<<endl;
}

int Patient::getpatNo()
{
  return patNo;
}

int Patient::getadmit()
{
  return admit;
}

void Patient::record()
{
  int y=0,n=0;
  Patient p;
  ifstream ifs;
  ifs.open("PantientDetails.dat",ios::in|ios::binary);
  ifs.seekg(0);
  while(ifs.read((char*)&p,sizeof(p)))
  {
	if(p.getadmit()=='Y'||p.getadmit()=='y')
	{
	  y++;
	}
	if(p.getadmit()=='N'||p.getadmit()=='n')
	{
	  n++;
	}
  }

  cout<<"No. of patients admitted: "<<y<<endl;
  cout<<"No. of patients not admitted : "<<n<<endl;
  cout<<"No. of patients visited :"<<(y+n)<<endl;
  cout<<"Total collection: "<<((1000*n)+(10000*y))<<endl;
 ifs.close();

}



void Patient::getDetails()
{
  int f=1;
  Patient p;
  ifstream ifs;
  ifs.open("PantientDetails.dat",ios::in|ios::binary);
  int vPat;
  cout<<"\nEnter Patient Number : ";
  cin>>vPat;
  ifs.seekg(0);

  while(ifs.read((char*)&p,sizeof(p)))
  {
	if(vPat==p.getpatNo())
	{
	  cout<<"\nPatient found.\n"<<endl;
	  p.dispDetails();
	  f=0;
	  break;
	}
	if(f==1)
	{
	  cout<<"\nPatient not found.\n"<<endl;
	  ifs.close();
	}
  }
}


void Patient::emergency()
{
			 Emergency = 'Y';
			clrscr();
			int emer;
			  cout<<"********************************************"<<endl;
			  cout<<"         GH Hospital EMERGENCY              "<<endl;
			  cout<<"********************************************"<<endl;
			  cout<<"\nPlease enter the nature of your emergency..."<<endl;
			  cout<<"\n 1. Physical Injury"<<endl;
		      cout<<" 2. Childbirth"<<endl;
		      cout<<" 3. Medico-Legal Case"<<endl;
		      cout<<" 4. Other\n"<<endl;
		      cin>>emer;

	      char Req[3];
	      strcpy(docConsult,Req);

	      switch(emer){
		    case 1: strcpy(Req,"PHY");
		    case 2: strcpy(Req,"GYN");
		    case 3: strcpy(Req,"MLC");
		    case 4: strcpy(Req,"OTH");
	      }


}

void Patient::patModify()
{
  fstream file;
  Patient p;
  file.open("PantientDetails.dat",ios::in|ios::out|ios::ate|ios::binary);
  int vPat,F=1;
  cout<<"\nEnter Patient Number : ";
  cin>>vPat;
  file.seekg(0);
  while(file)
  {
    int pos=file.tellg();
    file.read((char*)&p,sizeof(p));
    if(vPat==p.getpatNo())
    {
      F=0;
      cout<<"Patient details are "<<endl;
      p.dispDetails();
      cout<<"Enter record modifications "<<endl;
      p.setDetails('M');
      file.seekp(pos,ios::beg);
      file.write((char*)&p,sizeof(p));
      cout<<"Patient reocrd modified"<<endl;
      break;
    }
    if(F==1)
      cout<<"Patient not found";
  }
}

void Patient::Discharge()
{
  Patient p;
  ofstream ofs;
  ifstream ifs;
  ifs.open("PantientDetails.dat",ios::in|ios::binary);
  ofs.open("Temp.dat",ios::out|ios::binary);
  int vPat;
  if(!ifs)
  {
    cout<<"Record under maintanance. Cant access at the moment.Try Again";
    getch();
    exit(0);
  }
  ifs.seekg(0);
  cout<<"Enter Patient No. to be discharged "<<endl;
  cin>>vPat;
  while(!ifs.eof())
  {
    ifs.read((char*)&p,sizeof(p));
    if(vPat!=p.getpatNo())
    {
      ofs.write((char*)&p,sizeof(p));
    }
  }
  remove("PantientDetails.dat");
  rename("Temp.dat","PantientDetails.dat");
  cout<<"Patient has been discharged"<<endl;
  cout<<"Thankyou"<<endl;
  ifs.close();
  ofs.close();
}

//Main Function-----------------------------------------------------------------
//------------------------------------------------------------------------------


void main()
{
  char quit='N';
  Doctor D;
  nurse N;
  Patient P;

  do{

	clrscr();
		cout<<"********************************************"<<endl;
		cout<<"          WELCOME to GH Hospital            "<<endl;
		cout<<"********************************************"<<endl;
		cout<<"\n                Main Menu                 "<<endl;
		cout<<"\n1. Enter new Patient"<<endl;
		cout<<"\n2. Staff Entry"<<endl;
		cout<<"\n3. View Patient Details"<<endl;
		cout<<"\n4. View Staff Details"<<endl;
      cout<<"\n5. Modify Patient Details"<<endl;
      cout<<"\n6. Discharge Patient"<<endl;
      cout<<"\n7. Day Record"<<endl;
      cout<<"\n8. View all Records"<<endl;
		cout<<"\n9. Quit \n\n"<<endl;

		int ch;
		cin>>ch;

		switch(ch){

			  case 1:
					 clrscr();
				  P.PatDetails();
				  break;

			  case 2:
					clrscr();
				  int s;
				  cout<<"********************************************"<<endl;
				  cout<<"          GH Hospital Staff Entry           "<<endl;
				  cout<<"********************************************"<<endl;
				  cout<<"\n1. Doctor"<<endl;
				  cout<<"\n2. Nurse\n"<<endl;
				  cin>>s;

				  switch(s){

					 case 1:   D.docCheckin();
						   break;

					 case 2:   N.Checkin();
						   break;
				  }

				  break;

			  case 3:
              clrscr();
				  char view3;
				  do{
                 P.getDetails();
				     cout<<"View another Patient? (Y/N)...";
				     cin>>view3;

				  }while(view3=='Y'||view3=='y');
				  break;

        case 4:
          clrscr();
          char view4;
          do{
            int s;
            clrscr();
            cout<<"********************************************"<<endl;
            cout<<"         GH Hospital Staff Details          "<<endl;
            cout<<"********************************************"<<endl;
            cout<<"\n1. Doctor"<<endl;
            cout<<"\n2. Nurse\n"<<endl;
            cin>>s;

            switch(s){

	    case 1:   D.getdocDetails();
                break;

            case 2:   N.getDetails();
                break;
            }

            cout<<"\nView Another Employee? (Y/N)...";
	    cin>>view4;
          }while(view4=='Y'||view4=='y');
          break;

			  case 5:
          clrscr();
				  char view5;
				  do{

				     P.patModify();

				     cout<<"Modify another Patient's details? (Y/N)...";
				     cin>>view5;

				  }while(view5=='Y'||view5=='y');
				  break;

        case 6:
          clrscr();
          char view6;
          do{

              P.Discharge();

              cout<<"Discharge another Patient? (Y/N)...";
              cin>>view6;

          }while(view6=='Y'||view6=='y');
          break;

        case 7:
          clrscr();
          P.record();
          getch();
          break;

        case 8:
          clrscr();
          char view8;
          do{
            int s;
            clrscr();
            cout<<"**************************************"<<endl;
            cout<<"         GH Hospital Records          "<<endl;
            cout<<"**************************************"<<endl;
            cout<<"\n1. Doctor"<<endl;
            cout<<"\n2. Nurse\n";
            cout<<"\n3. Patient\n"<<endl;
            cin>>s;

            switch(s){

	    case 1:   D.docdisall();
                break;

       case 2:   N.nurdisall();
                break;

       case 3:   P.disall();
       			  break;
            }

            cout<<"\nView Another Record? (Y/N)...";
	    cin>>view8;
          }while(view8=='Y'||view8=='y');
          break;

        case 9:
          cout<<"\nAre you sure? (Y/N)...";
          cin>>quit;

	if(quit=='Y'|| quit=='y')
          break;

   if(quit=='N'|| quit=='n')
          break;

        default:
          cout<<"Invalid. Try again.";
          getch();

		}

  }while(quit=='N'||quit=='n');

   cout<<"\n\n\nPROGRAM TERMINATED"<<endl;
   getch();

}