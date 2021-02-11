#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
#include <stdlib.h>

const char VL = 179, HL = 196, TL = 218, TR = 191, BL = 192, BR = 217;
const char DVL = 186, DHL = 205, DTL = 201, DTR = 187, DBL = 200, DBR = 188;

//MAIN MENU

void Color(int TC, int BC) //For Changing Text Color and Text Background
{
	textcolor(TC);
	textbackground(BC);
}

void ShowXY(int X, int Y, char CH) //Displays a character at X,Y position
{
	gotoxy(X, Y);
	cprintf("%c", CH); //cout<<CH;
}

void ShowXY(int X, int Y, char CH[]) //Displays a string at X,Y position
{
	gotoxy(X, Y);
	cprintf("%s", CH); //cout<<CH;
}

void Vline(int X, int Y, int L) //To vertical line by joining vert. characters
{
	for (int i = Y; i <= Y + L; i++)
		ShowXY(X, i, VL);
}
void Hline(int X, int Y, int L) //To horizontal line by joining hor.characters
{
	for (int i = X; i <= X + L; i++)
		ShowXY(i, Y, HL);
}
void Recta(int C1, int R1, int C2, int R2)
{
	ShowXY(C1, R1, TL);				//
	ShowXY(C1, R2, BL);				//Placing corner characters
	ShowXY(C2, R1, TR);				//
	ShowXY(C2, R2, BR);				//
	Vline(C1, R1 + 1, R2 - R1 - 2); //
	Vline(C2, R1 + 1, R2 - R1 - 2); //Joining Corners by Vertical lines
	Hline(C1 + 1, R1, C2 - C1 - 2); //
	Hline(C1 + 1, R2, C2 - C1 - 2); //Joining Corners by Horizontal lines
}
void DVline(int X, int Y, int L)
{
	for (int i = Y; i <= Y + L; i++)
		ShowXY(X, i, DVL);
}
void DHline(int X, int Y, int L)
{
	for (int i = X; i <= X + L; i++)
		ShowXY(i, Y, DHL);
}
void DRecta(int C1, int R1, int C2, int R2)
{
	ShowXY(C1, R1, DTL);
	ShowXY(C1, R2, DBL);
	ShowXY(C2, R1, DTR);
	ShowXY(C2, R2, DBR);
	DVline(C1, R1 + 1, R2 - R1 - 2);
	DVline(C2, R1 + 1, R2 - R1 - 2);
	DHline(C1 + 1, R1, C2 - C1 - 2);
	DHline(C1 + 1, R2, C2 - C1 - 2);
}

//X,Y are coordinates for displaying menu
//Mnu all choices which required to be displayed as Menu Choices
//Noc no. of choices
int Vmenu(int X, int Y, char Mnu[][20], int Noc)
{
	Color(BLACK, WHITE);
	Recta(X, Y, X + strlen(Mnu[0]) + 1, Y + Noc + 1);
	for (int i = 0; i < Noc; i++)
		ShowXY(X + 1, Y + i + 1, Mnu[i]);

	int Sel = 0, Exit = 0; //Sel - Current Selected Option
						   //Exit- Control Variable for loop
	do
	{
		int Tsel = Sel; //To store the current selection in Tsel
		Color(WHITE, RED);
		ShowXY(X + 1, Y + Sel + 1, Mnu[Sel]);
		Color(BLACK, WHITE);
		char Cho = getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch (Cho)
		{
		case 71:
			Sel = 0;
			break;
		case 79:
			Sel = Noc - 1;
			break;
		case 72:
			if (Sel == 0)
				Sel = Noc - 1;
			else
				Sel--;
			break;
		case 80:
			if (Sel == Noc - 1)
				Sel = 0;
			else
				Sel++;
			break;
		case 13:
			Exit = 1; //Enter Key
			break;
		case 27:
			Sel = -1; //Escape
			Exit = 1;
			break;
		}
		ShowXY(X + 1, Y + Tsel + 1, Mnu[Tsel]);
	} while (!Exit);
	return Sel;
}

int Hmenu(int X, int Y, char Mnu[][20], int Noc)
{
	Color('C', YELLOW);
	for (int i = 0; i < Noc; i++)
		ShowXY(X + 15 * i + 1, Y, Mnu[i]);
	int Sel = 0, Exit = 0;
	do
	{
		int Tsel = Sel; //To store the current selection in Tsel
		Color(1, 'C');
		ShowXY(X + 15 * Sel + 1, Y, Mnu[Sel]);
		Color(WHITE, 'E');
		char Cho = getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch (Cho)
		{
		case 71:
			Sel = 0;
			break;
		case 79:
			Sel = Noc - 1;
			break;
		case 75:
			if (Sel == 0)
				Sel = Noc - 1;
			else
				Sel--;
			break;
		case 77:
			if (Sel == Noc - 1)

				Sel = 0;
			else
				Sel++;
			break;
		case 13:
			Exit = 1;
			break;
		case 27:
			Sel = -1;
			Exit = 1;
			break;
		}
		ShowXY(X + 15 * Tsel + 1, Y, Mnu[Tsel]);
	} while (!Exit);
	return Sel;
}

void ClearArea(int C1, int R1, int C2, int R2)
{
	window(C1, R1, C2, R2);
	clrscr();
	window(1, 1, 80, 25);
}
//Main menu over

//CLASS TRAIN
class Train
{
	long int tno;
	int fare;
	char tname[80], from[50], to[50];

public:
	void add();
	int rtno()
	{
		return (tno);
	}
	char *rtname()
	{
		return (tname);
	}
	void Show();
	void Changef(int f)
	{
		fare = f;
	}
	int rfare()
	{
		return (fare);
	}
};

void Train::add()
{
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "ADD TRAIN:\n");
	ShowXY(9, 9, "Enter Train No.:");
	cin >> tno;
	ShowXY(9, 11, "Enter Train Name:");
	gets(tname);
	ShowXY(9, 13, "From:");
	gets(from);
	ShowXY(9, 15, "To:");
	gets(to);
	ShowXY(9, 17, "Fare:");
	cin >> fare;

	getch();
}

void Train::Show()
{

	ShowXY(9, 10, "Train No.: ");
	cout << tno;
	ShowXY(35, 10, "Train Name: ");
	puts(tname);
	ShowXY(9, 12, "From: ");
	puts(from);
	ShowXY(35, 12, "To: ");
	puts(to);

	getch();
}

//STRUTURE passngr
struct passngr
{
	char Name[20], Address[300], Gender;
	long int Mobile, Aadhar;
	int r, s;
};

//CLASS Passenger
class Passenger
{
	long int tno;
	int n, r, s;
	char from[40], to[40];
	passngr P[10];

public:
	void add(int);
	void show(int);

	void rcb(int i)
	{
		cout << char(P[i].r);
		cout << P[i].s;
	}

	char *rpname(int i)
	{
		return (P[i].Name);
	}
	void ctno(int t)
	{
		tno = t;
	}
	int rtno()
	{
		return (tno);
	}
	void cn(int no)
	{
		n = no;
	}
	int rtn()
	{
		return (n);
	}
};

void Passenger ::add(int i)
{
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "ENTER DETAILS OF PASSENGER");
	cout << i + 1;
	ShowXY(9, 40, ":");
	ShowXY(9, 10, "Name: ");
	gets(P[i].Name);
	ShowXY(35, 10, "Gender(M/F):");
	cin >> P[i].Gender;
	ShowXY(9, 12, "Mobile No.:");
	cin >> P[i].Mobile;
	ShowXY(35, 12, "Aadhar No.:");
	cin >> P[i].Aadhar;
	ShowXY(9, 14, "Address:");
	gets(P[i].Address);
	P[i].r = 65 + random(5);
	P[i].s = 1 + random(9);

	getch();
}
void Passenger ::show(int i)
{
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 9, "Name: ");
	puts(P[i].Name);
	ShowXY(35, 9, "Gender(M/F):");
	cout << P[i].Gender;
	ShowXY(9, 11, "Mobile No.:");
	cout << P[i].Mobile;
	ShowXY(35, 11, "Aadhar No.:");
	cout << P[i].Aadhar;
	ShowXY(9, 13, "Address:");
	puts(P[i].Address);
	getch();
}

//Admin Fn
void Addtrain();
void Deletetrain();
void ModifyFare();
void PASS(int &ch)
{
	char pass[20];
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(21, 9, "Enter The Admin Password:");
	cin >> pass;
	if (strcmpi(pass, "KKGR") != 0)
	{
		ShowXY(30, 11, "WRONG PASSWORD!");
		ch = 3;
	}
	getch();
}
void ADMIN()
{
	char SMenu[][20] = {"Add Train      ",
						"Modify Fare    ",
						"Delete Train   "};
	int ch;
	ch = Vmenu(5, 2, SMenu, 3);
	PASS(ch);
	switch (ch)
	{
	case 0:
		Addtrain();
		break;
	case 1:
		ModifyFare();
		break;
	case 2:
		Deletetrain();
		break;
	}
}

//ADD FN.

void Addtrain()
{
	fstream f("TRAIN.DAT", ios::binary | ios::out | ios::app);
	Train T;
	char ch;
	do
	{
		T.add();
		f.write((char *)&T, sizeof(T));
		ShowXY(9, 21, "Want to add more(y/n)? ");
		cin >> ch;
	} while (ch == 'y');

	getch();
}

//Modify fn
void ModifyFare()
{
	int t, fare, n = 0, c = 0;
	clrscr();
	Color(RED, 1);
	ShowXY(9, 9, "Enter Train No.:");
	cin >> t;
	Train T;
	fstream f("TRAIN.DAT", ios::binary | ios::in | ios::out);
	while (c == 0 && f.read((char *)&T, sizeof(T)))
	{
		n++;
		if (t == T.rtno())
		{
			c = 1;
			ShowXY(9, 11, "Old Fare: Rs. ");
			cout << T.rfare();
			ShowXY(9, 13, "Enter New Fare: ");

			cin >> fare;
			T.Changef(fare);
			f.seekp((n - 1) * sizeof(T));
			f.write((char *)&T, sizeof(T));
			ShowXY(9, 16, "The fare has been changed!");
		}
	}
	if (c == 0)
		ShowXY(9, 15, "Train Not Found!");
	f.close();
	getch();
}

//Delete FN
void Transfer(char FN1[], char FN2[])
{
	fstream Fil1, Fil2;
	Train T;
	Fil1.open(FN1, ios::binary | ios::in);
	Fil2.open(FN2, ios::binary | ios::out);
	while (Fil1.read((char *)&T, sizeof(T)))
		Fil2.write((char *)&T, sizeof(T));
	Fil1.close();
	Fil2.close();
}

void Deletetrain()
{
	fstream f1("TRAIN.DAT", ios::binary | ios::in);
	fstream f2("TEMP.DAT", ios::binary | ios::out);
	Train T;
	int tno;
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "Enter Train No. to be deleted: ");
	cin >> tno;
	int D = 0;
	while (f1.read((char *)&T, sizeof(T)))
	{
		if (tno != T.rtno())
			f2.write((char *)&T, sizeof(T));
		else
		{
			T.Show();
			D = 1;
		}
	}
	if (D == 0)
		ShowXY(9, 14, "Record Not found!");
	else
		ShowXY(9, 14, "Record Deleted!");
	Transfer("TEMP.DAT", "TRAIN.DAT");
	f1.close();
	f2.close();
	getch();
}

//Over1

//USER FN
void Reserve();
void Cancel();
void USER()
{
	char SMenu[][20] = {
		"Reserve      ",
		"Cancel       ",
	};
	int ch;
	ch = Vmenu(20, 2, SMenu, 2);
	switch (ch)
	{
	case 0:
		Reserve();
		break;
	case 1:
		Cancel();
		break;
	}
}

//Reserve fn
void Reserve()
{
	int tno, n;
	fstream f1("TRAIN.DAT", ios::binary | ios::in);
	fstream f2("PASS.DAT", ios::binary | ios::out | ios::app);
	Train T;
	Passenger P;
	int c = 0;
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "BOOK YOUR TICKET HERE!");
	ShowXY(9, 10, "Pls Enter Train No.:");
	cin >> tno;
	while (c == 0 && f1.read((char *)&T, sizeof(T)))
	{
		if (tno == T.rtno())
		{
			P.ctno(tno);
			c = 1;
			ShowXY(9, 12, "Fare per passenger is: Rs. ");
			cout << T.rfare();
			ShowXY(9, 14, "Enter no. of passengers(Max 4): ");
			cin >> n;
			P.cn(n);
			ShowXY(9, 16, "Total fare is= Rs.");
			cout << n * T.rfare() << endl;
			getch();
			for (int i = 0; i < n; i++)
			{
				P.add(i);
			}
			f2.write((char *)&P, sizeof(P));
		}
	}

	if (c == 0)
		ShowXY(9, 16, "You Have Entered A Wrong Train No.!");
	else
		ShowXY(9, 17, "Your data has been recorded!");
	f1.close();
	f2.close();
	getch();
}
//Cancel fn
void Cancel()
{
	fstream f1("PASS.DAT", ios::binary | ios::in);
	fstream f2("TEMP.DAT", ios::binary | ios::out);
	Passenger P;
	int tno, c = 0, D = 0;
	char pname[100];
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "Enter Train No.: ");
	cin >> tno;
	while (f1.read((char *)&P, sizeof(P)))
	{
		if (tno == P.rtno())
		{
			c = 1;
			ShowXY(9, 9, "Enter Passenger Name : ");
			gets(pname);
			for (int i = 0; i < P.rtn(); i++)
				if (strcmpi(pname, P.rpname(i)) != 0)
					f2.write((char *)&P, sizeof(P));
				else
				{
					P.show(i);
					D = 1;
				}
		}
	}

	if (c == 0)
		ShowXY(9, 14, "You Have Entered A Wrong Train No.!");
	else if (D == 0)
		ShowXY(9, 14, "You Have Entered Wrong Passenger Name!");
	else
		ShowXY(9, 16, "Record Deleted!");
	Transfer("TEMP.DAT", "PASS.DAT");
	f1.close();
	f2.close();
	getch();
}
//over 2
//Search FN.
void SearchTno();
void SearchTname();

void SearchTrain()
{
	char SMenu[][20] = {
		"BY TRAIN NO.    ",
		"BY TRAIN NAME   ",
	};
	int ch;
	ch = Vmenu(38, 3, SMenu, 2);
	switch (ch)
	{
	case 0:
		SearchTno();
		break;
	case 1:
		SearchTname();
		break;
	}
}

void SearchTno()
{
	long int tno, C = 0;
	fstream f("TRAIN.DAT", ios::binary | ios::in);
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "Enter Train No. to be Searched: ");
	cin >> tno;
	Train T;
	while (C == 0 && f.read((char *)&T, sizeof(T)))
	{

		if (tno == T.rtno())
		{
			T.Show();
			C = 1;
		}
	}
	if (C == 0)
		ShowXY(9, 15, "No Record Found!");
	getch();
	f.close();
}

void SearchTname()
{
	char tname[20];
	int c = 0;
	fstream f("TRAIN.DAT", ios::binary | ios::in);
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(9, 7, "Enter Train Name to be Searched: ");
	gets(tname);
	Train T;
	while (c == 0 && f.read((char *)&T, sizeof(T)))
	{
		if (strcmpi(tname, T.rtname()) == 0)
		{
			T.Show();
			c = 1;
		}
	}
	if (c == 0)
		ShowXY(9, 15, "Train Not Found!");
	getch();
	f.close();
}

//REPORTS
void PDetail();
void RStatus();

void REPORTS()
{
	char SMenu[][20] = {
		"Passenger Detail   ",
		"Chart List         ",
	};
	int ch;
	ch = Vmenu(50, 2, SMenu, 2);
	switch (ch)
	{
	case 0:
		PDetail();
		break;
	case 1:
		RStatus();
		break;
	}
}

//Passenger Detail Fn
void PDetail()
{
	randomize();
	fstream f1("PASS.DAT", ios::binary | ios::in);
	clrscr();
	Passenger P;
	Color(BLUE, WHITE);
	int tno, c = 0, d = 0;
	char pname[80];
	ShowXY(9, 7, "Check Your Passenger Details Here: ");
	ShowXY(9, 10, "Enter Your Train No.:");
	cin >> tno;
	while (c == 0 && f1.read((char *)&P, sizeof(P)))
	{
		if (tno == P.rtno())
		{
			c = 1;
			ShowXY(9, 12, "Enter Passenger Name:");
			gets(pname);
			for (int i = 0; i < P.rtn(); i++)
				if (strcmpi(pname, P.rpname(i)) == 0)
				{
					d = 1;
					P.show(i);
					ShowXY(9, 15, "Your Seat No.is: ");
					P.rcb(i);
					ShowXY(9, 17, "We hope you will have an enjoyable journey!");
				}
		}
	}
	if (c == 0)
		ShowXY(9, 15, "You Have Entered A Wrong Train No.");
	else if (d == 0)
		ShowXY(9, 15, "You Have Entered Wrong Passenger Name");

	getch();
	f1.close();
}

//Chart List
void RStatus()
{
	fstream f1("PASS.DAT", ios::binary | ios::in);
	Passenger P;
	int tno, i = 9;
	clrscr();
	Color(BLUE, WHITE);
	ShowXY(23, 3, "RESERVATION STATUS:");
	ShowXY(9, 5, "Enter Train No.:");
	cin >> tno;
	while (f1.read((char *)&P, sizeof(P)))
	{
		ShowXY(9, 7, "__PASSENGER NAME__");
		ShowXY(35, 7, "__SEAT NO.__");
		if (tno == P.rtno())
		{
			for (int j = 0; j < P.rtn(); j++)
			{
				ShowXY(11, i, "");
				cout << P.rpname(j);
				ShowXY(37, i, "");
				P.rcb(j);
				i += 2;
			}
		}
	}
	getch();
	f1.close();
}
//over3
//QUIT
void QUIT()
{
	clrscr();
	Color(BLUE, GREEN);
	ShowXY(12, 5, "Thank You!!");
	ShowXY(30, 19, "PLEASE VISIT TO OUR PORTAL AGAIN!");
}
//over 4

void main()
{

	char MainMenu[][20] = {"ADMIN     ",
						   "USER      ",
						   "SEARCH\n\b\b\bTRAIN  ",
						   "REPORTS   ",
						   "QUIT    "};

	int Ch;
	do
	{
		Color(BROWN, YELLOW);
		clrscr();

		Ch = Hmenu(4, 1, MainMenu, 5);

		switch (Ch)
		{
		case 0:
			ADMIN();
			break;
		case 1:
			USER();
			break;
		case 2:
			SearchTrain();
			break;
		case 3:
			REPORTS();
			break;
		case 4:
			QUIT();
			getch();
			break;
		}
	} while (Ch != 4);
}
