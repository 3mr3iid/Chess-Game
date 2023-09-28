#include<iostream>
#include<stdlib.h>
using namespace std;
class Board
{
private:
	struct B
	{
		int Xcor;
		int Ycor;
		int Pos;
		string Name;
		bool isempty;
		int Player;
	};
	struct RecycleBin
	{
		string Name;
		int Player;
	};
	int IndexR;
	B b[8][8];
	RecycleBin r[64];
	void Initialize()
	{
		IndexR = 0;
		for (int i = 0; i < 64; i++)
		{
			r[i].Name = "";
			r[i].Player = 0;
		}
		int c = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++, c++)
			{
				b[i][j].Xcor = j;
				b[i][j].Ycor = 7 - i;
				b[i][j].Pos = c;
				if (b[i][j].Pos >= 48 && b[i][j].Pos <= 55)
				{
					b[i][j].Name = "S1";
					b[i][j].isempty = false;
					b[i][j].Player = 1;
				}
				else if (b[i][j].Pos >= 8 && b[i][j].Pos <= 15)
				{
					b[i][j].Name = "S2";
					b[i][j].isempty = false;
					b[i][j].Player = 2;
				}
				else if (b[i][j].Pos == 1 || b[i][j].Pos == 6)
				{
					b[i][j].Name = "H2";
					b[i][j].isempty = false;
					b[i][j].Player = 2;
				}
				else if (b[i][j].Pos == 57 || b[i][j].Pos == 62)
				{
					b[i][j].Name = "H1";
					b[i][j].isempty = false;
					b[i][j].Player = 1;
				}
				else if (b[i][j].Pos == 56 || b[i][j].Pos == 63)
				{
					b[i][j].Name = "R1";
					b[i][j].isempty = false;
					b[i][j].Player = 1;
				}
				else if (b[i][j].Pos == 0 || b[i][j].Pos == 7)
				{
					b[i][j].Name = "R2";
					b[i][j].isempty = false;
					b[i][j].Player = 2;
				}
				else if (b[i][j].Pos == 58 || b[i][j].Pos == 61)
				{
					b[i][j].Name = "B1";
					b[i][j].isempty = false;
					b[i][j].Player = 1;
				}
				else if (b[i][j].Pos == 2 || b[i][j].Pos == 5)
				{
					b[i][j].Name = "B2";
					b[i][j].isempty = false;
					b[i][j].Player = 2;
				}
				else if (b[i][j].Pos == 59)
				{
					b[i][j].Name = "Q1";
					b[i][j].isempty = false;
					b[i][j].Player = 1;
				}
				else if (b[i][j].Pos == 3)
				{
					b[i][j].Name = "Q2";
					b[i][j].isempty = false;
					b[i][j].Player = 2;
				}
				else if (b[i][j].Pos == 60)
				{
					b[i][j].Name = "K1";
					b[i][j].isempty = false;
					b[i][j].Player = 1;
				}
				else if (b[i][j].Pos == 4)
				{
					b[i][j].Name = "K2";
					b[i][j].isempty = false;
					b[i][j].Player = 2;
				}
				else
				{
					b[i][j].Name = "";
					b[i][j].isempty = true;
					b[i][j].Player = 0;
				}
			}
		}
	}
public:
	void AddToRecycleBin(int Pos)
	{
		int i = Geti(Pos), j = Getj(Pos);
		r[IndexR].Name = b[i][j].Name;
		r[IndexR].Player = b[i][j].Player;
		IndexR++;
	}
	void DisplayRecycleBin()
	{
		if (IndexR == 0)
		{
			cout << "Recycle Bin is empty!!" << endl;
		}
		else
		{
			cout << "Piece\tPlayer" << endl;
			for (int i = 0; i < IndexR; i++)
			{
				cout << r[i].Name << '\t' << r[i].Player << endl;
			}
		}
	}
	bool isPositionEmpty(int Pos)
	{
		return b[Geti(Pos)][Getj(Pos)].isempty;
	}
	string Piece(int Pos)
	{
		return b[Geti(Pos)][Getj(Pos)].Name;
	}
	void ResetCell(int Pos)
	{
		int i = Geti(Pos), j = Getj(Pos);
		b[i][j].Name = "";
		b[i][j].isempty = true;
		b[i][j].Player = 0;
	}
	void AssignCell(int Pos, string N, int Player)
	{
		int i = Geti(Pos), j = Getj(Pos);
		b[i][j].Name = N;
		b[i][j].isempty = false;
		b[i][j].Player = Player;
	}
	int Player(int Pos)
	{
		return b[Geti(Pos)][Getj(Pos)].Player;
	}
	Board()
	{
		Initialize();
	}
	int GetPos(int x, int y)
	{
		return ((7 - y) * 8) + x;
	}
	void DisplayBoard()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << '(' << b[i][j].Name << ',' << b[i][j].Pos << ')' << '\t';
			}
			cout << endl << endl << endl;
		}
	}
	void ReverseBoard()
	{
		for (int i = 7; i >= 0; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << '(' << b[i][j].Name << ',' << b[i][j].Pos << ')' << '\t';
			}
			cout << endl << endl << endl;
		}
	}
	int GetXcor(int Pos)
	{
		int i = Geti(Pos), j = Getj(Pos);
		if (Pos == b[i][j].Pos)
		{
			return b[i][j].Xcor;
		}
		return -1;
	}
	int GetYcor(int Pos)
	{
		int i = Geti(Pos), j = Getj(Pos);
		if (Pos == b[i][j].Pos)
		{
			return b[i][j].Ycor;
		}
		return -1;
	}
	int Geti(int Pos)
	{
		return Pos / 8;
	}
	int Getj(int Pos)
	{
		return Pos - (Geti(Pos) * 8);
	}
};
class Soldier
{
private:
	struct S
	{
		string Name;
		int Pos;
		bool FirstMove;
	};
	S s[2][8];
	void Getij(int Pos, int& x, int& y)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (Pos == s[i][j].Pos)
				{
					x = i;
					y = j;
				}
			}
		}
	}
	void ChangeSoldierPos(int u, int v, Board& B)
	{
		int i, j;
		Getij(u, i, j);
		s[i][j].Pos = v;
		s[i][j].FirstMove = false;
	}
	void RemoveSoldier(int Pos)
	{
		int i, j;
		Getij(Pos, i, j);
		s[i][j].Pos = -1;
		s[i][j].Name = "";
		s[i][j].FirstMove = false;
	}
	void Initialize()
	{
		IndexP = 0;
		int x = 48;
		int y = 8;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i == 0)
				{
					s[i][j].Pos = x;
					s[i][j].Name = "S1";
					s[i][j].FirstMove = true;
					x++;
				}
				else
				{
					s[i][j].Pos = y;
					s[i][j].Name = "S2";
					s[i][j].FirstMove = true;
					y++;
				}
			}
		}
	}
	void Eat(int u, int v, Board& B, int Player)
	{
		int i, j;
		Getij(u, i, j);
		string N = s[i][j].Name;
		B.AddToRecycleBin(v);
		ChangeSoldierPos(u, v, B);
		B.AssignCell(v, N, Player);
		B.ResetCell(u);
	}
	bool FirstMove(int Pos)
	{
		int i, j;
		Getij(Pos, i, j);
		return s[i][j].FirstMove;
	}
	bool CanEat(int u, int v, Board& B, int Player)
	{
		if (B.Player(u) != B.Player(v) && B.Player(v)!=0)
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (!B.isPositionEmpty(u))
			{
				if ((B.Piece(u) == "S1" || B.Piece(u) == "S2") && (Player == B.Player(u)) && (((dx == 1 || dx == -1) && dy == 1 && Player == 1)) || ((dx == 1 || dx == -1) && dy == -1 && Player == 2))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool XXXCanEat(int u, int v, Board& B, int Player)
	{
		float dx = B.GetXcor(v) - B.GetXcor(u);
		float dy = B.GetYcor(v) - B.GetYcor(u);
		if (!B.isPositionEmpty(u))
		{
			if ((B.Piece(u) == "S1" || B.Piece(u) == "S2") && (Player == B.Player(u)) && (((dx == 1 || dx == -1) && dy == 1 && Player == 1)) || ((dx == 1 || dx == -1) && dy == -1 && Player == 2))
			{
				return true;
			}
		}
		return false;
	}
	void CalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	bool CanMove(int u, int v, Board& B, int Player)
	{
		if (B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (!B.isPositionEmpty(u))
			{
				int g = 2, k = 1;
				if ((B.isPositionEmpty(v)) && (B.Piece(u) == "S1" || B.Piece(u) == "S2") && (Player == B.Player(u)))
				{
					if (Player == 2)
					{
						g *= -1;
						k *= -1;
					}
					if (dx == 0)
					{
						if (FirstMove(u))
						{
							if (dy == g)
							{
								if (Player == 1)
								{
									if (B.isPositionEmpty(B.GetPos(B.GetXcor(u), B.GetYcor(u) + 1)))
									{
										return true;
									}
								}
								else if (Player == 2)
								{
									if (B.isPositionEmpty(B.GetPos(B.GetXcor(u), B.GetYcor(u) - 1)))
									{
										return true;
									}
								}
							}
							else if (dy == g - k)
							{
								return true;
							}
						}
						else if (dy == g - k)
						{
							return true;
						}
					}
				}
				else if ((!B.isPositionEmpty(v)) && (B.Piece(u) == "S1" || B.Piece(u) == "S2") && (Player == B.Player(u)) && (((dx == 1 || dx == -1) && dy == 1 && Player == 1)) || ((dx == 1 || dx == -1) && dy == -1 && Player == 2))
				{
					return true;
				}
			}
		}
		return false;
	}
public:
	bool Move(int u, int v, Board& B, int Player)
	{
		if (B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (!B.isPositionEmpty(u))
			{
				int m, n, g = 2, k = 1;
				Getij(u, m, n);
				string N = s[m][n].Name;
				if ((B.isPositionEmpty(v)) && (B.Piece(u) == "S1" || B.Piece(u) == "S2") && (Player == B.Player(u)))
				{
					if (Player == 2)
					{
						g *= -1;
						k *= -1;
					}
					if (dx == 0)
					{
						if (FirstMove(u))
						{
							if (dy == g)
							{
								if (Player == 1)
								{
									if (B.isPositionEmpty(B.GetPos(B.GetXcor(u), B.GetYcor(u) + 1)))
									{
										ChangeSoldierPos(u, v, B);
										B.AssignCell(v, N, Player);
										B.ResetCell(u);
										return true;
									}
								}
								else if (Player == 2)
								{
									if (B.isPositionEmpty(B.GetPos(B.GetXcor(u), B.GetYcor(u) - 1)))
									{
										ChangeSoldierPos(u, v, B);
										B.AssignCell(v, N, Player);
										B.ResetCell(u);
										return true;
									}
								}
							}
							else if (dy == g - k)
							{
								ChangeSoldierPos(u, v, B);
								B.AssignCell(v, N, Player);
								B.ResetCell(u);
								return true;
							}
						}
						else if (dy == g - k)
						{
							ChangeSoldierPos(u, v, B);
							B.AssignCell(v, N, Player);
							B.ResetCell(u);
							return true;
						}
					}
				}
				else if ((!B.isPositionEmpty(v)) && (B.Piece(u) == "S1" || B.Piece(u) == "S2") && (Player == B.Player(u)) && (((dx == 1 || dx == -1) && dy == 1 && Player == 1)) || ((dx == 1 || dx == -1) && dy == -1 && Player == 2))
				{
					Eat(u, v, B, Player);
					return true;
				}
			}
		}
		return false;
	}
	void CalculatePossibleEats(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanEat(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	void XXXCalculatePossibleEats(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (XXXCanEat(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	Soldier()
	{
		Initialize();
	}
	int IndexP;
	int Possible[63];
	void DisplayPossibleMoves(int u, Board& B, int Player)
	{
		CalculatePossibleMoves(u, B, Player);
		if (IndexP == 0)
		{
			cout << "You cannot move this piece!!" << endl;
		}
		else
		{
			cout << "Possiblie Positions are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP = 0;
	}
	void DisplayPossibleEats(int u, Board& B, int Player)
	{
		CalculatePossibleEats(u, B, Player);
		if (IndexP == 0)
		{
			cout << "You cannot eat any piece!!" << endl;
		}
		else
		{
			cout << "Possiblie eats are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP = 0;
	}
};
class Rook
{
private:
	struct R
	{
		int Pos;
		string Name;
		bool FirstMove;
	};
	int Index;
	R r[20];
	int Geti(int Pos)
	{
		for (int i = 0; i < Index; i++)
		{
			if (Pos == r[i].Pos)
			{
				return i;
			}
		}
		return -1;
	}
	void RemoveRook(int Pos)
	{
		int i = Geti(Pos);
		r[i].Pos = -1;
		r[i].Name = "";
		r[i].FirstMove = false;
	}
	bool isPathwayClear(int u, int v, Board& B)
	{
		int n = 1;
		int Xu = B.GetXcor(u);
		int Yu = B.GetYcor(u);
		int Xv = B.GetXcor(v);
		int Yv = B.GetYcor(v);
		if (Xv - Xu != 0 && Yv - Yu == 0)
		{
			if (Xv < Xu)
			{
				n *= -1;
				Xu--;
			}
			else
			{
				Xu++;
			}
			while (Xu != Xv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu += n;
			}
		}
		else if (Yv - Yu != 0 && Xv == Xu)
		{
			if (Yv < Yu)
			{
				n *= -1;
				Yu--;
			}
			else
			{
				Yu++;
			}
			while (Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Yu += n;
			}
		}
		return true;
	}
	void ChangeRookPos(int u, int v, Board& B)
	{
		int i = Geti(u);
		r[i].Pos = v;
		r[i].FirstMove = false;
	}
	void Eat(int u, int v, Board& B, int Player)
	{
		int i = Geti(u);
		string N = r[i].Name;
		B.AddToRecycleBin(v);
		ChangeRookPos(u, v, B);
		B.AssignCell(v, N, Player);
		B.ResetCell(u);
	}
	bool CanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (((B.Piece(u) == "R1" || B.Piece(u) == "R2") && (Player == B.Player(u))) && ((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) && (isPathwayClear(u, v, B)))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	bool XXXCanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (((B.Piece(u) == "R1" || B.Piece(u) == "R2") && (Player == B.Player(u))) && ((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) && (isPathwayClear(u, v, B)))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	void Initialize()
	{
		Index=4;
		IndexP = 0;
		r[0].Pos = 56;
		r[0].Name = "R1";
		r[0].FirstMove = true;
		r[1].Pos = 63;
		r[1].Name = "R1";
		r[1].FirstMove = true;
		r[2].Pos = 0;
		r[2].Name = "R2";
		r[2].FirstMove = true;
		r[3].Pos = 7;
		r[3].Name = "R2";
		r[3].FirstMove = true;
	}
public:
	void newRook(int Pos, int Player, Board& B)
	{
		r[Index].Pos = Pos;
		if (Player == 1)
		{
			r[Index].Name = "R1";
		}
		else
		{
			r[Index].Name = "R2";
		}
		r[Index].FirstMove = true;
		B.ResetCell(Pos);
		B.AssignCell(Pos, r[Index].Name, Player);
		Index++;
	}
	void CalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	void XXXCalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (XXXCanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	int IndexP;
	int Possible[63];
	void DisplayPossibleMoves(int u, Board& B, int Player)
	{
		CalculatePossibleMoves(u, B, Player);
		if (IndexP == 0)
		{
			cout << "You cannot move this piece!!" << endl;
		}
		else
		{
			cout << "Possiblie Positions are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP = 0;
	}
	bool Move(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			int i = Geti(u);
			string N = r[i].Name;
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "R1" || B.Piece(u) == "R2") && (Player == B.Player(u))) && ((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) && (isPathwayClear(u, v, B)))
			{
				if (B.isPositionEmpty(v))
				{
					ChangeRookPos(u, v, B);
					B.AssignCell(v, N, Player);
					B.ResetCell(u);
					return true;
				}
				else
				{
					Eat(u, v, B, Player);
					return true;
				}
			}
		}
		return false;
	}
	Rook()
	{
		Initialize();
	}

};
class Horse
{
private:
	struct H
	{
		int Pos;
		string Name;
	};
	H h[20];
	int Index;
	int Geti(int Pos)
	{
		for (int i = 0; i < Index; i++)
		{
			if (h[i].Pos == Pos)
			{
				return i;
			}
		}
		return -1;
	}
	void RemoveHorse(int Pos)
	{
		int i = Geti(Pos);
		h[i].Pos = -1;
		h[i].Name = "";
	}
	void ChangeHorsePos(int u, int v, Board& B)
	{
		int i = Geti(u);
		h[i].Pos = v;
	}
	void Eat(int u, int v, Board& B, int Player)
	{
		int i = Geti(u);
		string N = h[i].Name;
		B.AddToRecycleBin(v);
		ChangeHorsePos(u, v, B);
		B.AssignCell(v, N, Player);
		B.ResetCell(u);
	}
	bool CanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "H1" || B.Piece(u) == "H2") && (Player == B.Player(u))) && ((m == 0.5 || m == -0.5 || m == 2 || m == -2) && (dx == 2 || dx == -2 || dx == 1 || dx == -1) && (dy == 2 || dy == -2 || dy == 1 || dy == -1)))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	bool XXXCanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "H1" || B.Piece(u) == "H2") && (Player == B.Player(u))) && ((m == 0.5 || m == -0.5 || m == 2 || m == -2) && (dx == 2 || dx == -2 || dx == 1 || dx == -1) && (dy == 2 || dy == -2 || dy == 1 || dy == -1)))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	void Initialize()
	{
		Index = 4;
		IndexP = 0;
		h[0].Pos = 57;
		h[0].Name = "H1";
		h[1].Pos = 62;
		h[1].Name = "H1";
		h[2].Pos = 1;
		h[2].Name = "H2";
		h[3].Pos = 6;
		h[3].Name = "H2";
	}
public:
	void newHorse(int Pos, int Player, Board& B)
	{
		h[Index].Pos = Pos;
		if (Player == 1)
		{
			h[Index].Name = "H1";
		}
		else
		{
			h[Index].Name = "H2";
		}
		B.ResetCell(Pos);
		B.AssignCell(Pos, h[Index].Name, Player);
		Index++;
	}
	void CalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	void XXXCalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (XXXCanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	int IndexP;
	int Possible[63];
	void DisplayPossibleMoves(int u, Board& B, int Player)
	{
		CalculatePossibleMoves(u, B, Player);
		if (IndexP == 0)
		{
			cout << "You cannot move this piece!!" << endl;
		}
		else
		{
			cout << "Possiblie Positions are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP = 0;
	}
	Horse()
	{
		Initialize();
	}
	bool Move(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			int i = Geti(u);
			string N = h[i].Name;
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "H1" || B.Piece(u) == "H2") && (Player == B.Player(u))) && ((m == 0.5 || m == -0.5 || m == 2 || m == -2) && (dx == 2 || dx == -2 || dx == 1 || dx == -1) && (dy == 2 || dy == -2 || dy == 1 || dy == -1)))
			{
				if (B.isPositionEmpty(v))
				{
					ChangeHorsePos(u, v, B);
					B.AssignCell(v, N, Player);
					B.ResetCell(u);
					return true;
				}
				else
				{
					Eat(u, v, B, Player);
					return true;
				}
			}
		}
		return false;
	}
};
class Bishop
{
private:
	struct B
	{
		int Pos;
		string Name;
	};
	B b[20];
	int Index;
	int Geti(int Pos)
	{
		for (int i = 0; i < Index; i++)
		{
			if (Pos == b[i].Pos)
			{
				return i;
			}
		}
		return -1;
	}
	void ChangeBishopPos(int u, int v, Board& B)
	{
		int i = Geti(u);
		b[i].Pos = v;
	}
	void Eat(int u, int v, Board& B, int Player)
	{
		int i = Geti(u);
		string N = b[i].Name;
		B.AddToRecycleBin(v);
		ChangeBishopPos(u, v, B);
		B.AssignCell(v, N, Player);
		B.ResetCell(u);
	}
	bool CanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "B1" || B.Piece(u) == "B2") && (Player == B.Player(u))) && ((m == 1) || (m == -1)) && (isPathwayClear(u, v, B)))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	bool XXXCanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "B1" || B.Piece(u) == "B2") && (Player == B.Player(u))) && ((m == 1) || (m == -1)) && (isPathwayClear(u, v, B)))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	bool isPathwayClear(int u, int v, Board& B)
	{
		int n = 1;
		int Xu = B.GetXcor(u);
		int Yu = B.GetYcor(u);
		int Xv = B.GetXcor(v);
		int Yv = B.GetYcor(v);
		int dx = Xv - Xu;
		int dy = Yv - Yu;
		if (dx > 0 && dy > 0)
		{
			Xu++;
			Yu++;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu++;
				Yu++;
			}
		}
		else if (dx > 0 && dy < 0)
		{
			Xu++;
			Yu--;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu++;
				Yu--;
			}
		}
		else if (dx < 0 && dy > 0)
		{
			Xu--;
			Yu++;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu--;
				Yu++;
			}
		}
		else if (dx < 0 && dy < 0)
		{
			Xu--;
			Yu--;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu--;
				Yu--;
			}
		}
		return true;
	}
	void Initialize()
	{
		Index = 4;
		IndexP = 0;
		b[0].Pos = 58;
		b[0].Name = "B1";
		b[1].Pos = 61;
		b[1].Name = "B1";
		b[2].Pos = 2;
		b[2].Name = "B2";
		b[3].Pos = 5;
		b[3].Name = "B2";
	}
public:
	void newBishop(int Pos, int Player, Board& B)
	{
		b[Index].Pos = Pos;
		if (Player == 1)
		{
			b[Index].Name = "B1";
		}
		else
		{
			b[Index].Name = "B2";
		}
		B.ResetCell(Pos);
		B.AssignCell(Pos, b[Index].Name, Player);
		Index++;
	}
	void CalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	void XXXCalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (XXXCanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	int IndexP;
	int Possible[63];
	void DisplayPossibleMoves(int u, Board& B, int Player)
	{
		CalculatePossibleMoves(u, B, Player);
		if (IndexP == 0)
		{
			cout << "You cannot move this piece!!" << endl;
		}
		else
		{
			cout << "Possiblie Positions are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP = 0;
	}
	Bishop()
	{
		Initialize();
	}
	bool Move(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			int i = Geti(u);
			string N = b[i].Name;
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "B1" || B.Piece(u) == "B2") && (Player == B.Player(u))) && ((m == 1) || (m == -1)) && (isPathwayClear(u, v, B)))
			{
				if (B.isPositionEmpty(v))
				{
					ChangeBishopPos(u, v, B);
					B.AssignCell(v, N, Player);
					B.ResetCell(u);
					return true;
				}
				else
				{
					Eat(u, v, B, Player);
					return true;
				}
			}
		}
		return false;
	}
};
class Queen
{
private:
	struct Q
	{
		int Pos;
		string Name;
	};
	Q q[18];
	int Index;
	int Find(int Pos)
	{
		for (int i = 0; i < Index; i++)
		{
			if (q[i].Pos == Pos)
			{
				return i;
			}
		}
		return -1;
	}
	void ChangeQueenPos(int u, int v, Board& B)
	{
		q[Find(u)].Pos = v;
	}
	void Eat(int u, int v, Board& B, int Player)
	{
		string N = q[Find(u)].Name;
		B.AddToRecycleBin(v);
		ChangeQueenPos(u, v, B);
		B.AssignCell(v, N, Player);
		B.ResetCell(u);
	}
	bool CanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "Q1" || B.Piece(u) == "Q2") && (Player == B.Player(u))) && (((m == 1) || (m == -1)) || (((dx != 0 && dy == 0) || (dx == 0 && dy != 0)))) && isPathwayClear(u, v, B))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	bool XXXCanMove(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "Q1" || B.Piece(u) == "Q2") && (Player == B.Player(u))) && (((m == 1) || (m == -1)) || (((dx != 0 && dy == 0) || (dx == 0 && dy != 0)))) && isPathwayClear(u, v, B))
			{
				if (B.isPositionEmpty(v))
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	bool isPathwayClear(int u, int v, Board& B)
	{
		int n = 1;
		int Xu = B.GetXcor(u);
		int Yu = B.GetYcor(u);
		int Xv = B.GetXcor(v);
		int Yv = B.GetYcor(v);
		int dx = Xv - Xu;
		int dy = Yv - Yu;
		if (dx > 0 && dy > 0)
		{
			Xu++;
			Yu++;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu++;
				Yu++;
			}
		}
		else if (dx > 0 && dy < 0)
		{
			Xu++;
			Yu--;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu++;
				Yu--;
			}
		}
		else if (dx < 0 && dy > 0)
		{
			Xu--;
			Yu++;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu--;
				Yu++;
			}
		}
		else if (dx < 0 && dy < 0)
		{
			Xu--;
			Yu--;
			while (Xu != Xv && Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu--;
				Yu--;
			}
		}
		else if (Xv - Xu != 0 && Yv - Yu == 0)
		{
			if (Xv < Xu)
			{
				n *= -1;
				Xu--;
			}
			else
			{
				Xu++;
			}
			while (Xu != Xv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Xu += n;
			}
		}
		else if (Yv - Yu != 0 && Xv == Xu)
		{
			if (Yv < Yu)
			{
				n *= -1;
				Yu--;
			}
			else
			{
				Yu++;
			}
			while (Yu != Yv)
			{
				if (!B.isPositionEmpty(B.GetPos(Xu, Yu)))
				{
					return false;
				}
				Yu += n;
			}
		}
		return true;
	}
	void Initialize()
	{
		Index = 2;
		IndexP = 0;
		q[0].Pos = 59;
		q[0].Name = "Q1";
		q[1].Pos = 3;
		q[1].Name = "Q2";
	}
public:
	void newQueen(int Pos, int Player, Board& B)
	{
		q[Index].Pos = Pos;
		if (Player == 1)
		{
			q[Index].Name = "Q1";
		}
		else
		{
			q[Index].Name = "Q2";
		}
		B.ResetCell(Pos);
		B.AssignCell(Pos, q[Index].Name, Player);
		Index++;
	}
	void CalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	void XXXCalculatePossibleMoves(int u, Board& B, int Player)
	{
		for (int i = 0; i < 64; i++)
		{
			if (XXXCanMove(u, i, B, Player))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	int IndexP;
	int Possible[63];
	void DisplayPossibleMoves(int u, Board& B, int Player)
	{
		CalculatePossibleMoves(u, B, Player);
		if (IndexP == 0)
		{
			cout << "You cannot move this piece!!" << endl;
		}
		else
		{
			cout << "Possiblie Positions are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP = 0;
	}
	Queen()
	{
		Initialize();
	}
	bool Move(int u, int v, Board& B, int Player)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			string N = q[Find(u)].Name;
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			float m = dy / dx;
			if (((B.Piece(u) == "Q1" || B.Piece(u) == "Q2") && (Player == B.Player(u))) && (((m == 1) || (m == -1)) || (((dx != 0 && dy == 0) || (dx == 0 && dy != 0)))) && isPathwayClear(u, v, B))
			{
				if (B.isPositionEmpty(v))
				{
					ChangeQueenPos(u, v, B);
					B.AssignCell(v, N, Player);
					B.ResetCell(u);
					return true;
				}
				else
				{
					Eat(u, v, B, Player);
					return true;
				}
			}
		}
		return false;
	}
};
class King
{
private:
	struct K
	{
		int Pos;
		string Name;
		bool FirstMove;
		bool UnderAttack;
	};
	int Possible[63];
	int IndexP;
	K k[2];
	void Initialize()
	{
		IndexP = 0;
		k[0].Pos = 60;
		k[0].Name = "K1";
		k[0].FirstMove = true;
		k[0].UnderAttack = false;
		k[1].Pos = 4;
		k[1].Name = "K2";
		k[1].FirstMove = true;
		k[1].UnderAttack = false;
	}
	int Find(int Pos)
	{
		for (int i = 0; i < 2; i++)
		{
			if (k[i].Pos == Pos)
			{
				return i;
			}
		}
		return -1;
	}
	void ChangeKingPos(int u, int v, Board& B)
	{
		k[Find(u)].Pos = v;
		k[Find(u)].FirstMove = false;
		k[Find(u)].UnderAttack = false;
	}
	void Eat(int u, int v, Board& B, int Player)
	{
		string N = k[Find(u)].Name;
		B.AddToRecycleBin(v);
		ChangeKingPos(u, v, B);
		B.AssignCell(v, N, Player);
		B.ResetCell(u);
	}
	void CalculatePossibleMoves(int u, Board& B, int Player, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		for (int i = 0; i < 64; i++)
		{
			if (CanMove(u, i, B, Player, S, R, H, BB, Q))
			{
				Possible[IndexP] = i;
				IndexP++;
			}
		}
	}
	bool CanMove(int u, int v, Board& B, int Player, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (((B.Piece(u) == "K1" || B.Piece(u) == "K2") && (Player == B.Player(u))) && ((dx == 1 && dy == 0) || (dy == 1 && dx == 0) || (dx == -1 && dy == 0) || (dy == -1 && dx == 0) || (dx == 1 && dy == 1) || (dx == -1 && dy == 1) || (dx == -1 && dy == -1) || (dx == 1 && dy == -1)))
			{
				if (CanBeEaten(v, Player, B, S, R, H, BB, Q) == -1)
				{
					if (B.isPositionEmpty(v))
					{
						return true;
					}
					else
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	void Set(int& Num, int New)
	{
		Num = New;
	}
public:
	int CanBeEaten(int Pos, int Player, Board& B, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		int OtherPlayer = 0;
		if (Player == 1)
		{
			Set(OtherPlayer, 2);
		}
		else
		{
			Set(OtherPlayer, 1);
		}
		if (B.Player(Pos) != Player)
		{
			for (int i = 0; i < 64; i++)
			{
				if ((B.Piece(i) == "S1" || B.Piece(i) == "S2") && B.Player(i) != Player)
				{
					S.XXXCalculatePossibleEats(i, B, OtherPlayer);
					for (int j = 0; j < S.IndexP; j++)
					{
						if (Pos == S.Possible[j])
						{
							S.IndexP = 0;
							return i;
						}
					}
					S.IndexP = 0;
				}
				else if ((B.Piece(i) == "R1" || B.Piece(i) == "R2") && B.Player(i) != Player)
				{
					R.XXXCalculatePossibleMoves(i, B, OtherPlayer);
					for (int j = 0; j < R.IndexP; j++)
					{
						if (Pos == R.Possible[j])
						{
							R.IndexP = 0;
							return i;
						}
					}
					R.IndexP = 0;
				}
				else if ((B.Piece(i) == "H1" || B.Piece(i) == "H2") && B.Player(i) != Player)
				{
					H.XXXCalculatePossibleMoves(i, B, OtherPlayer);
					for (int j = 0; j < H.IndexP; j++)
					{
						if (Pos == H.Possible[j])
						{
							H.IndexP = 0;
							return i;
						}
					}
					H.IndexP = 0;
				}
				else if ((B.Piece(i) == "B1" || B.Piece(i) == "B2") && B.Player(i) != Player)
				{
					BB.XXXCalculatePossibleMoves(i, B, OtherPlayer);
					for (int j = 0; j < BB.IndexP; j++)
					{
						if (Pos == BB.Possible[j])
						{
							BB.IndexP = 0;
							return i;
						}
					}
					BB.IndexP = 0;
				}
				else if ((B.Piece(i) == "Q1" || B.Piece(i) == "Q2") && B.Player(i) != Player)
				{
					Q.XXXCalculatePossibleMoves(i, B, OtherPlayer);
					for (int j = 0; j < Q.IndexP; j++)
					{
						if (Pos == Q.Possible[j])
						{
							Q.IndexP = 0;
							return i;
						}
					}
					Q.IndexP = 0;
				}
				else if ((B.Piece(i) == "K1" || B.Piece(i) == "K2") && B.Player(i) != Player)
				{
					int dx = abs(abs(B.GetXcor(i)) - abs(B.GetXcor(Pos)));
					int dy = abs(abs(B.GetYcor(i)) - abs(B.GetYcor(Pos)));
					if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1))
					{
						return i;
					}
				}
			}
		}
		return -1;
	}
	void DisplayPossibleMoves(int u, Board& B, int Player, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		CalculatePossibleMoves(u, B, Player, S, R, H, BB, Q);
		if (IndexP == 0)
		{
			cout << "You cannot move this piece!!" << endl;
		}
		else
		{
			cout << "Possiblie Positions are : " << endl;
			for (int i = 0; i < IndexP; i++)
			{
				cout << Possible[i] << endl;
			}
		}
		IndexP=0;
	}
	King()
	{
		Initialize();
	}
	bool Move(int u, int v, Board& B, int Player, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		if (!B.isPositionEmpty(u) && B.Player(u) != B.Player(v))
		{
			string N = k[Find(u)].Name;
			float dx = B.GetXcor(v) - B.GetXcor(u);
			float dy = B.GetYcor(v) - B.GetYcor(u);
			if (((B.Piece(u) == "K1" || B.Piece(u) == "K2") && (Player == B.Player(u))) && ((dx == 1 && dy == 0) || (dy == 1 && dx == 0) || (dx == -1 && dy == 0) || (dy == -1 && dx == 0) || (dx == 1 && dy == 1) || (dx == -1 && dy == 1) || (dx == -1 && dy == -1) || (dx == 1 && dy == -1)))
			{
				if (CanBeEaten(v, Player, B, S, R, H, BB, Q) == -1)
				{
					if (B.isPositionEmpty(v))
					{
						ChangeKingPos(u, v, B);
						B.AssignCell(v, N, Player);
						B.ResetCell(u);
						return true;
					}
					else
					{
						Eat(u, v, B, Player);
						return true;
					}
				}
			}
		}
		return false;
	}
	int King1UnderAtt(Board& B, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		for (int i = 0; i < 64; i++)
		{
			if (B.Player(i) == 2)
			{
				if (B.Piece(i) == "S2")
				{
					S.CalculatePossibleEats(i, B, 2);
					for (int j = 0; j < S.IndexP; j++)
					{
						if (k[0].Pos == S.Possible[j])
						{
							k[0].UnderAttack = true;
							S.IndexP = 0;
							return i;
						}
					}
					S.IndexP = 0;
				}
				else if (B.Piece(i) == "R2")
				{
					R.CalculatePossibleMoves(i, B, 2);
					for (int j = 0; j < R.IndexP; j++)
					{
						if (k[0].Pos == R.Possible[j])
						{
							k[0].UnderAttack = true;
							R.IndexP = 0;
							return i;
						}
					}
					R.IndexP = 0;
				}
				else if (B.Piece(i) == "H2")
				{
					H.CalculatePossibleMoves(i, B, 2);
					for (int j = 0; j < H.IndexP; j++)
					{
						if (k[0].Pos == H.Possible[j])
						{
							k[0].UnderAttack = true;
							H.IndexP = 0;
							return i;
						}
					}
					H.IndexP = 0;
				}
				else if (B.Piece(i) == "B2")
				{
					BB.CalculatePossibleMoves(i, B, 2);
					for (int j = 0; j < BB.IndexP; j++)
					{
						if (k[0].Pos == BB.Possible[j])
						{
							k[0].UnderAttack = true;
							BB.IndexP = 0;
							return i;
						}
					}
					BB.IndexP = 0;
				}
				else if (B.Piece(i) == "Q2")
				{
					Q.CalculatePossibleMoves(i, B, 2);
					for (int j = 0; j < Q.IndexP; j++)
					{
						if (k[0].Pos == Q.Possible[j])
						{
							k[0].UnderAttack = true;
							Q.IndexP = 0;
							return i;
						}
					}
					Q.IndexP = 0;
				}
			}
		}
		return -1;
	}
	int King2UnderAtt(Board& B, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		for (int i = 0; i < 64; i++)
		{
			if (B.Player(i) == 1)
			{
				if (B.Piece(i) == "S1")
				{
					S.CalculatePossibleEats(i, B, 1);
					for (int j = 0; j < S.IndexP; j++)
					{
						if (k[1].Pos == S.Possible[j])
						{
							k[1].UnderAttack = true;
							S.IndexP = 0;
							return i;
						}
					}
					S.IndexP = 0;
				}
				else if (B.Piece(i) == "R1")
				{
					R.CalculatePossibleMoves(i, B, 1);
					for (int j = 0; j < R.IndexP; j++)
					{
						if (k[1].Pos == R.Possible[j])
						{
							k[1].UnderAttack = true;
							R.IndexP = 0;
							return i;
						}
					}
					R.IndexP = 0;
				}
				else if (B.Piece(i) == "H1")
				{
					H.CalculatePossibleMoves(i, B, 1);
					for (int j = 0; j < H.IndexP; j++)
					{
						if (k[1].Pos == H.Possible[j])
						{
							k[1].UnderAttack = true;
							H.IndexP = 0;
							return i;
						}
					}
					H.IndexP = 0;
				}
				else if (B.Piece(i) == "B1")
				{
					BB.CalculatePossibleMoves(i, B, 1);
					for (int j = 0; j < BB.IndexP; j++)
					{
						if (k[1].Pos == BB.Possible[j])
						{
							k[1].UnderAttack = true;
							BB.IndexP = 0;
							return i;
						}
					}
					BB.IndexP = 0;
				}
				else if (B.Piece(i) == "Q1")
				{
					Q.CalculatePossibleMoves(i, B, 1);
					for (int j = 0; j < Q.IndexP; j++)
					{
						if (k[1].Pos == Q.Possible[j])
						{
							k[1].UnderAttack = true;
							Q.IndexP = 0;
							return i;
						}
					}
					Q.IndexP = 0;
				}
			}
		}
		return -1;
	}
	bool CanInterruptPathway1(Board& B, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		int EnemyPos = King1UnderAtt(B, S, R, H, BB, Q);
		if (B.Piece(EnemyPos) == "R2" || B.Piece(EnemyPos) == "B2" || B.Piece(EnemyPos) == "Q2")
		{

		}
		return false;
	}
	bool CanInterruptPathway2(Board& B, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		int EnemyPos = King2UnderAtt(B, S, R, H, BB, Q);
		if (B.Piece(EnemyPos) == "R1" || B.Piece(EnemyPos) == "B1" || B.Piece(EnemyPos) == "Q1")
		{

		}
		return false;
	}
	bool GameOver(Board& B, Soldier& S, Rook& R, Horse& H, Bishop& BB, Queen& Q)
	{
		if (King1UnderAtt(B, S, R, H, BB, Q)!=-1)
		{
			CalculatePossibleMoves(k[0].Pos, B, 1, S, R, H, BB, Q);
			if (IndexP > 0)
			{
				IndexP = 0;
				return false;
			}
			int EnemyPos = King1UnderAtt(B, S, R, H, BB, Q);
			if (CanMove(k[0].Pos, EnemyPos, B, 1, S, R, H, BB, Q))
			{
				return false;
			}
			for (int i = 0; i < 64; i++)
			{
				if (B.Player(i) == 1)
				{
					if (B.Piece(i) == "S1")
					{
						S.CalculatePossibleEats(i, B, 1);
						for (int j = 0; j < S.IndexP; j++)
						{
							if (EnemyPos == S.Possible[j])
							{
								S.IndexP = 0;
								return false;
							}
						}
						S.IndexP = 0;
					}
					else if (B.Piece(i) == "R1")
					{
						R.CalculatePossibleMoves(i, B, 1);
						for (int j = 0; j < R.IndexP; j++)
						{
							if (EnemyPos == R.Possible[j])
							{
								R.IndexP = 0;
								return false;
							}
						}
						R.IndexP = 0;
					}
					else if (B.Piece(i) == "H1")
					{
						H.CalculatePossibleMoves(i, B, 1);
						for (int j = 0; j < H.IndexP; j++)
						{
							if (EnemyPos == H.Possible[j])
							{
								H.IndexP = 0;
								return false;
							}
						}
						H.IndexP = 0;
					}
					else if (B.Piece(i) == "B1")
					{
						BB.CalculatePossibleMoves(i, B, 1);
						for (int j = 0; j < BB.IndexP; j++)
						{
							if (EnemyPos == BB.Possible[j])
							{
								BB.IndexP = 0;
								return false;
							}
						}
						BB.IndexP = 0;
					}
					else if (B.Piece(i) == "Q1")
					{
						Q.CalculatePossibleMoves(i, B, 1);
						for (int j = 0; j < Q.IndexP; j++)
						{
							if (EnemyPos == Q.Possible[j])
							{
								Q.IndexP = 0;
								return false;
							}
						}
						Q.IndexP = 0;
					}
				}
			}
			if (CanInterruptPathway1(B,S,R,H,BB,Q))
			{
				return false;
			}
			return true;
		}
		if (King2UnderAtt(B, S, R, H, BB, Q)!=-1)
		{
			CalculatePossibleMoves(k[1].Pos, B, 2, S, R, H, BB, Q);
			if (IndexP > 0)
			{
				IndexP = 0;
				return false;
			}  
			int EnemyPos = King2UnderAtt(B, S, R, H, BB, Q);
			if (CanMove(k[1].Pos, EnemyPos, B, 2, S, R, H, BB, Q))
			{
				return false;
			}
			for (int i = 0; i < 64; i++)
			{
				if (B.Player(i) == 2)
				{
					if (B.Piece(i) == "S2")
					{
						S.CalculatePossibleEats(i, B, 2);
						for (int j = 0; j < S.IndexP; j++)
						{
							if (EnemyPos == S.Possible[j])
							{
								S.IndexP = 0;
								return false;
							}
						}
						S.IndexP = 0;
					}
					else if (B.Piece(i) == "R2")
					{
						R.CalculatePossibleMoves(i, B, 2);
						for (int j = 0; j < R.IndexP; j++)
						{
							if (EnemyPos == R.Possible[j])
							{
								R.IndexP = 0;
								return false;
							}
						}
						R.IndexP = 0;
					}
					else if (B.Piece(i) == "H2")
					{
						H.CalculatePossibleMoves(i, B, 2);
						for (int j = 0; j < H.IndexP; j++)
						{
							if (EnemyPos == H.Possible[j])
							{
								H.IndexP = 0;
								return false;
							}
						}
						H.IndexP = 0;
					}
					else if (B.Piece(i) == "B2")
					{
						BB.CalculatePossibleMoves(i, B, 2);
						for (int j = 0; j < BB.IndexP; j++)
						{
							if (EnemyPos == BB.Possible[j])
							{
								BB.IndexP = 0;
								return false;
							}
						}
						BB.IndexP = 0;
					}
					else if (B.Piece(i) == "Q2")
					{
						Q.CalculatePossibleMoves(i, B, 2);
						for (int j = 0; j < Q.IndexP; j++)
						{
							if (EnemyPos == Q.Possible[j])
							{
								Q.IndexP = 0;
								return false;
							}
						}
						Q.IndexP = 0;
					}
				}
			}
			if (CanInterruptPathway2(B,S,R,H,BB,Q))
			{
				return false;
			}
			return true;
		}
		return false;
	}
};
int main()
{
	char x;
	do
	{
		Board B; Soldier S; King K; Rook R; Horse H; Bishop BB; Queen Q;
		int P = -1;
		int Player = 0;
		while (!K.GameOver(B, S, R, H, BB, Q))
		{
			system("cls");
			P = (P + 1) % 2;
			Player = P + 1;
			if (Player == 1)
			{
				B.DisplayBoard();
				B.DisplayRecycleBin();
			}
			else
			{
				B.ReverseBoard();
				B.DisplayRecycleBin();
			}
			cout<<"------------------------------------"<<endl;
			cout<<"Player "<<Player<<" Turn !! "<<endl;
			cout<<"------------------------------------"<<endl;
			int Choice;
			do
			{
				cout << "Choose from the following menu : " << endl;
				cout << "1.View possible moves of a piece." << endl;
				cout << "2.Move a piece" << endl;
				cout << "Enter your choice >> ";
				cin >> Choice;
				if (Choice == 1)
				{
					cout << "Enter the position of the piece >> ";
					int Pos; cin >> Pos;
					if (B.Piece(Pos) == "S1" || B.Piece(Pos) == "S2")
					{
						S.DisplayPossibleMoves(Pos, B, Player);
					}
					else if (B.Piece(Pos) == "R1" || B.Piece(Pos) == "R2")
					{
						R.DisplayPossibleMoves(Pos, B, Player);
					}
					else if (B.Piece(Pos) == "H1" || B.Piece(Pos) == "H2")
					{
						H.DisplayPossibleMoves(Pos, B, Player);
					}
					else if (B.Piece(Pos) == "B1" || B.Piece(Pos) == "B2")
					{
						BB.DisplayPossibleMoves(Pos, B, Player);
					}
					else if (B.Piece(Pos) == "Q1" || B.Piece(Pos) == "Q2")
					{
						Q.DisplayPossibleMoves(Pos, B, Player);
					}
					else if (B.Piece(Pos) == "K1" || B.Piece(Pos) == "K2")
					{
						K.DisplayPossibleMoves(Pos, B, Player, S, R, H, BB, Q);
					}
				}
				else
				{
					while(true)
					{
						cout << "Enter the initial position of the piece that you want to move >> ";
						int u; cin >> u;
						cout << "Enter the final position >> ";
						int v; cin >> v;
						if (B.Piece(u) == "S1" || B.Piece(u) == "S2")
						{
							if(S.Move(u,v,B,Player))
							{
								if ((Player == 1 && B.GetYcor(v) == 7) || (Player == 2 && B.GetYcor(v) == 0))
								{
									while (true)
									{
										cout << "Choose a chess piece : " << endl;
										cout << "1.Queen" << endl;
										cout << "2.Horse" << endl;
										cout << "3.Bishop" << endl;
										cout << "4.Rook" << endl;
										cout << "Enter your choice >> ";
										int Choice; cin >> Choice;
										if (Choice == 1)
										{
											Q.newQueen(v, Player, B);
											break;
										}
										else if (Choice == 2)
										{
											H.newHorse(v, Player, B);
											break;
										}
										else if (Choice == 3)
										{
											BB.newBishop(v, Player, B);
											break;
										}
										else if (Choice == 4)
										{
											R.newRook(v, Player, B);
											break;
										}
									}
								}
								break;
							}
							else
							{
								cout<<"Invalid Move !! "<<endl;
							}
						}	
						else if (B.Piece(u) == "R1" || B.Piece(u) == "R2")
						{
							if(R.Move(u,v,B,Player))
							{
								break;
							}
							else
							{
								cout<<"Invalid Move !! "<<endl;
							}
						}
						else if (B.Piece(u) == "H1" || B.Piece(u) == "H2")
						{
							if(H.Move(u,v,B,Player))
							{
								break;
							}
							else
							{
								cout<<"Invalid Move !! "<<endl;
							}
						}
						else if (B.Piece(u) == "B1" || B.Piece(u) == "B2")
						{
							if(BB.Move(u,v,B,Player))
							{
								break;
							}
							else
							{
								cout<<"Invalid Move !! "<<endl;
							}
						}
						else if (B.Piece(u) == "Q1" || B.Piece(u) == "Q2")
						{
							if(Q.Move(u,v,B,Player))
							{
								break;
							}
							else
							{
								cout<<"Invalid Move !! "<<endl;
							}
						}
						else if (B.Piece(u) == "K1" || B.Piece(u) == "K2")
						{
							if(K.Move(u,v,B,Player,S,R,H,BB,Q))
							{
								break;
							}
							else
							{
								cout<<"Invalid Move !! "<<endl;
							}
						}
					}
				}
			} while (Choice == 1);
		}
		cout << "Player " << Player << " Won !!"<<endl;
		cout << "Rematch?? (Y/N) : "; cin >> x;
		system("cls");
	} while (x == 'y' || x == 'Y');
}
