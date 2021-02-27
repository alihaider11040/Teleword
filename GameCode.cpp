#include<iostream>
#include<string>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<chrono>
using namespace std;
using namespace chrono;
void printarray(char A[500], int x) {
	x = strlen(A);
	for (int i = 0; i < x; i++)
	{
		cout << A[i];
	}
}
void gotoxy(int xpos, int ypos, int col, char ch)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
	HANDLE  screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(screen, col);
	DWORD useless;
	WriteConsole(screen, &ch, 1, (LPDWORD)&useless, NULL);
	SetConsoleTextAttribute(screen, 15);
	SMALL_RECT windowSize = { 0, 0, 100, 100 };
	SetConsoleWindowInfo(screen, TRUE, &windowSize);
}
void UTLS(char A[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			A[i][j] = A[i][j] + 32;

		}

	}
}
bool rowR(char Grid[15][15], char temp[50], int c[15][15], int(&rC)[15], int(&cC)[15]) {
	bool notMatch = true;
	int x, z = 0, j1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{
				j1 = j;
				z++;
				if (j != 0) { j--; };
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if (temp[z] == Grid[i][j])
					{
						notMatch = false;

					}
					else
					{
						notMatch = true;
					}
					z++;  j--;
				}
				if (notMatch == false)
				{

					for (int t = j1; t > j; t--)
					{
						c[i][t]++; cC[t]++;
					}
					rC[i]++;
					//printarray(temp, x); cout << '\n';
				}
				if (notMatch == true)
				{
					j = j1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
bool rowF(char Grid[15][15], char temp[50], int c[15][15], int(&rC)[15], int(&cC)[15]) {
	{
		bool notMatch = true;
		int x, z = 0, j1;
		x = strlen(temp);
		for (int i = 0; notMatch == true && i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (temp[z] == Grid[i][j])
				{
					j1 = j;
					z++; j++;
					notMatch = false;
					for (int k = 1; notMatch == false && k < x; k++)
					{
						if ((temp[z]) == Grid[i][j])
						{
							notMatch = false;
						}
						else
						{
							notMatch = true;
						}
						z++, j++;
					}
					if (notMatch == false)
					{
						for (int t = j1; t < j; t++)
						{
							c[i][t]++; cC[t]++;
						}
						rC[i]++;
						//printarray(temp, x); cout << '\n';
					}
					if (notMatch == true)
					{
						j = j1;
						z = 0;
					}
				}
			}
		}
		return notMatch;
	}
}
bool columnD(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	bool notMatch = true;
	int x, z = 0, i1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; notMatch == true && j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{
				i1 = i;
				z++; i++;
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if (temp[z] == Grid[i][j])
					{
						notMatch = false;
					}
					else
					{
						notMatch = true;
					}
					z++, i++;
				}
				if (notMatch == false)
				{
					for (int t = i1; t < i; t++)
					{
						c[t][j]++; rC[t]++;
					}//printarray(temp, x); cout << '\n';
					cC[j]++;
				}
				if (notMatch == true)
				{
					i = i1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
bool columnU(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	bool notMatch = true;
	int x, z = 0, i1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; notMatch == true && j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{

				i1 = i;
				z++; i--;
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if ((temp[z]) == Grid[i][j])
					{
						notMatch = false;
					}
					else
					{
						notMatch = true;
					}
					z++, i--;
				}
				if (notMatch == false)
				{

					for (int t = i1; t > i; t--)
					{
						c[t][j]++; rC[t]++;
					}//printarray(temp, x); cout << '\n';
					cC[j]++;
				}
				if (notMatch == true)
				{
					i = i1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
bool DiagonalF(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	bool notMatch = true;
	int x, z = 0, j1, i1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; notMatch == true && j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{
				j1 = j;
				i1 = i;
				z++; j++; i++;
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if ((temp[z]) == Grid[i][j])
					{
						notMatch = false;
					}
					else
					{

						notMatch = true;
					}
					z++, j++; i++;
				}
				if (notMatch == false)
				{
					for (int t = j1, s = i1; t < j && s < i; t++, s++)
					{
						c[s][t]++;
						cC[t]++;
						rC[s]++;
					}//printarray(temp, x); cout << '\n';

				}
				if (notMatch == true)
				{
					j = j1; i = i1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
bool DiagonalR(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	bool notMatch = true;
	int x, z = 0, j1, i1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; notMatch == true && j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{
				j1 = j;
				i1 = i;
				z++;
				if (i != 0 && j != 0)
				{
					j--; i--;
				}
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if (temp[z] == Grid[i][j])
					{
						notMatch = false;
					}
					else
					{
						notMatch = true;
					}
					z++; i--; j--;
				}
				if (notMatch == false)
				{
					for (int t = j1, s = i1; t > j && s > i; t--, s--)
					{
						c[s][t]++;
						rC[s]++;
						cC[t]++;
					}//printarray(temp, x); cout << '\n';

				}
				if (notMatch == true)
				{
					j = j1; i = i1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
bool Diagonal1R(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	bool notMatch = true;
	int x, z = 0, j1, i1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; notMatch == true && j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{
				j1 = j;
				i1 = i;
				z++;
				if (j != 0) { j--; }if (i != 14)
				{

					i++;
				}
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if (temp[z] == Grid[i][j])
					{
						notMatch = false;
					}
					else
					{
						notMatch = true;
					}
					z++, j--; i++;
				}
				if (notMatch == false)
				{
					for (int t = j1, s = i1; t > j && s < i; t--, s++)
					{
						c[s][t]++;
						cC[t]++;
						rC[s]++;
					}//printarray(temp, x); cout << '\n';
				}
				if (notMatch == true)
				{
					j = j1; i = i1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
bool Diagonal1F(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	bool notMatch = true;
	int x, z = 0, j1, i1;
	x = strlen(temp);
	for (int i = 0; notMatch == true && i < 15; i++)
	{
		for (int j = 0; notMatch == true && j < 15; j++)
		{
			if (temp[z] == Grid[i][j])
			{
				j1 = j;
				i1 = i;
				z++; j++; i--;
				notMatch = false;
				for (int k = 1; notMatch == false && k < x; k++)
				{
					if (temp[z] == Grid[i][j])
					{
						notMatch = false;
					}
					else
					{
						notMatch = true;
					}
					z++, j++; i--;
				}
				if (notMatch == false)
				{
					for (int t = j1, s = i1; t < j && s > i; t++, s--)
					{
						c[s][t]++;
						cC[t]++;
						rC[s];
					}
				}

				if (notMatch == true)
				{
					j = j1; i = i1;
					z = 0;
				}
			}
		}
	}
	return notMatch;
}
void UTLA(char A[50]) {
	int x = 0;
	x = strlen(A);
	for (int i = 0; i < x; i++)
	{
		if (A[i] > 64 && A[i] < 91)
		{
			A[i] = A[i] + 32;
		}
	}
}
void intake(int grid[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++) {

			grid[i][j] = 0;
		}
	}
}
void FindIT(char Grid[15][15], char temp[50], int c[15][15], int(&cC)[15], int(&rC)[15]) {
	UTLA(temp);
	if (rowF(Grid, temp, c, rC, cC)) {
		if (rowR(Grid, temp, c, rC, cC)) {
			if (columnD(Grid, temp, c, cC, rC)) {
				if (columnU(Grid, temp, c, cC, rC))
				{
					if (DiagonalF(Grid, temp, c, cC, rC))
					{
						if (DiagonalR(Grid, temp, c, cC, rC))
						{
							if (Diagonal1F(Grid, temp, c, cC, rC))
							{
								if (Diagonal1R(Grid, temp, c, cC, rC))
								{
								}
							}
						}
					}
				}
			}

		}
	}
}
void coloring(char Grid[15][15], int c[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			int x = 0;
			if (c[i][j] == 0) { x = 15; }
			if (c[i][j] == 1)
			{
				x = 14;
			}
			else
			{
				if (c[i][j] == 2)
				{
					x = 1;
				}
				else
				{
					if (c[i][j] > 2) { x = 4; }
				}
			}
			gotoxy(j, i, x, Grid[i][j]);
			x = 0;

		}
		cout << '\n';
	}
}
void print(char A[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{

			cout << A[i][j] << "  ";

		}
		cout << '\n';
	}
}
void steps(char Grid[15][15], char arr[500], int c[15][15], char GridU[15][15], int(&cC)[15], int(&rC)[15]) {
	char g;
	int x;
	x = strlen(arr);
	for (int i = 0; i < x; i++)
	{
		char temp[50];
		{
			int j = 0;
			for (j = 0; arr[i] != ',' && arr[i] != '.'; j++) {

				temp[j] = arr[i];
				i++;
			}
			temp[j] = '\0';
			i++;
			FindIT(GridU, temp, c, cC, rC);
			coloring(Grid, c);

			_getch();

		}
	}
}
void statistics(char Grid[15][15], char arr[500], int c[15][15], char GridU[15][15], int(&cC)[15], int(&rC)[15]) {
	int RR = 0, RF = 0, CD = 0, CU = 0, DF = 0, DR = 0, D1F = 0, D1R = 0, x = 0;
	x = strlen(arr);
	int maxLen = 0, minLen = 100, sum = 0, count = 0;
	for (int i = 0; i < x; i++)
	{
		char temp[50];

		int j = 0;
		for (j = 0; arr[i] != ',' && arr[i] != '.'; j++) {

			temp[j] = arr[i];
			i++;
		}
		temp[j] = '\0';
		i++;
		count++;
		int k = 0;
		k = strlen(temp);
		sum = sum + k;
		if (k > maxLen) { maxLen = k; }
		if (k < minLen) { minLen = k; }
		UTLA(temp);
		if (!rowF(GridU, temp, c, rC, cC)) { RF++; }
		if (!rowR(GridU, temp, c, rC, cC)) { RR++; }
		if (!columnD(GridU, temp, c, cC, rC)) { CD++; }
		if (!columnU(GridU, temp, c, cC, rC)) { CU++; }
		if (!DiagonalF(GridU, temp, c, cC, rC)) { DF++; }
		if (!DiagonalR(GridU, temp, c, cC, rC)) { DR++; }
		if (!Diagonal1F(GridU, temp, c, cC, rC)) { D1F++; }
		if (!Diagonal1R(GridU, temp, c, cC, rC)) { D1R++; }
	}
	cout << "longest word lenght: " << maxLen << ",  " << " " << "Shortest word length: " << minLen << ",  " << " " << "average length: " << (sum / count) << '\n';
	cout << "word Distribution: " << "Horizontal: " << (RR + RF) << "(" << RF << ", " << RR << ") " << " "
		<< "Vertical: " << (CD + CU) << "(" << CD << "," << CU << ")" << " "
		<< "Diagonals: " << (DF + DR + D1F + D1R) << "(" << (DF + D1F) << "," << (D1R + DR) << ")" << '\n';
	int scater = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++) {
			if (c[i][j] == 0) { j = 14; scater++; }
		}
	}
	cout << "Teleword Scatter: " << scater << '\n';
	int maxR = 0, maxC = 0, rmax = 0, cmax = 0;
	for (int i = 0; i < 8; i++)
	{
		if (maxR < rC[i]) { rmax = i; maxR = rC[i]; }
		if (maxC < cC[i]) { cmax = i; maxC = cC[i]; }
	}
	cout << "Heaviest row:  " << (rmax + 1) << '\n';
	cout << "Heaviest column:  " << (cmax + 1) << '\n';

}
void ans(char grid[15][15], int c[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++) {
			if (c[i][j] == 0)
			{
				cout << grid[i][j];
			}

		}
	}
	cout << '\n';
}
int main() {
	ifstream file("C:\\Users\\Ali Haider\\Desktop\\teleword_10.txt");
	if (file.fail())
	{
		cout << "ops";
	}
	else
	{
		char Grid[15][15], arr[500];
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				file >> Grid[i][j];
			}
		}
		file.getline(arr, 500);
		file.getline(arr, 500);
		file.getline(arr, 500);
		file.close();
		int x = 0, rC[15] = { 0 }, cC[15] = { 0 };
		x = strlen(arr);
		print(Grid);
		cout << endl;
		printarray(arr, x);
		char GridU[15][15];
		memcpy(GridU, Grid, 15 * 15);
		UTLS(GridU);
		int color[15][15];
		intake(color);
		char q;
		cout << '\n';

		cout << "Enter S to solve at once" << '\n' << "Enter T to slove step By step" << '\n' << "Enter X for statistics" << '\n';
		cin >> q;
		system("cls");
		auto start = high_resolution_clock::now();

		for (int i = 0; i < x; i++)
		{
			char temp[50];

			int j = 0;
			for (j = 0; arr[i] != ',' && arr[i] != '.'; j++) {

				temp[j] = arr[i];
				i++;
			}
			temp[j] = '\0';
			i++;
			FindIT(GridU, temp, color, cC, rC);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);

		if (q == 's') {
			coloring(Grid, color);
			cout << '\n';
			ans(Grid, color);
		}
		if (q == 't')
		{
			intake(color);
			steps(Grid, arr, color, GridU, rC, cC);
			cout << '\n';
			ans(Grid, color);

		}
		if (q == 'x') {
			intake(color);
			cout << "Time to solve= "
				<< duration.count() << " microseconds" << endl;
			statistics(Grid, arr, color, GridU, cC, rC);
		}
		for (int i = 0; i < 8; i++)
		{
			cout << cC[i] << "   ";
		}

		cout << '\n' << '\n';
		for (int i = 0; i < 8; i++)
		{
			cout << rC[i] << "   ";
		}

		cout << endl;
		system("pause");
	}
}