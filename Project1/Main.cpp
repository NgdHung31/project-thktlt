#include "Header.h"

int main()
{
	int log[1000];
	int top = -1;
	int dem = 0;

	LIST l;
	init(l);
	readFile(l);
	output(l);

	string chu;

	cout << "\n========= MENU ========= " << endl;
	cout << "Delete pos. " << endl;
	cout << "Insert pos val. " << endl;
	cout << "Undo" << endl;
	cout << "Redo" << endl;
	cout << "Save" << endl;
	cout << "Reset" << endl;
	cout << "Quit. " << endl;

	int n;
	do
	{
		cout << "\nCommand > : ";
		cin >> chu;

		if (chu == "Delete" || chu == "delete")
			n = 1;
		else if (chu == "Insert" || chu == "insert")
			n = 2;
		else if (chu == "Undo" || chu == "undo")
			n = 3;
		else if (chu == "Redo" || chu == "redo")
			n = 4;
		else if (chu == "Save" || chu == "save")
			n = 5;
		else if (chu == "Reset" || chu == "reset")
			n = 6;
		else if (chu == "Quit" || chu == "quit")
			n = 7;
		else
			n = 8;

		switch (n)
		{
		case 1:
		{
			dem += 3;

			int a = length(l);
			int k;
			cin >> k;
			if (k == 0 || k > a)
			{
				cout << "Wrong input, re-enter ! ";
			}
			else if (k == 1)
			{
				push(log, 1, top);
				push(log, k, top);
				push(log, l.pHead->data, top);
				deleteHead(l);
			}
			else if (k == a)
			{
				push(log, 1, top);
				push(log, k, top);
				push(log, l.pTail->data, top);
				deleteTail(l);
			}
			else
			{
				push(log, 1, top);
				push(log, k, top);
				push(log, printOutAt(l, k), top);
				deleteAt(l, k);
			}
			output(l);
			cout << endl;
			break;
		}
		case 2:
		{
			dem += 3;

			int a = length(l);
			int k;
			int x;
			cin >> k >> x;
			if (k == 0)
			{
				cout << "Wrong input, re-enter ! ";
			}
			if (k == 1)
			{
				push(log, 2, top);
				push(log, k, top);
				push(log, x, top);
				addHead(l, x);
			}
			else if (k == a + 1)
			{
				push(log, 2, top);
				push(log, k, top);
				push(log, x, top);
				addTail(l, x);
			}
			else
			{
				push(log, 2, top);
				push(log, k, top);
				push(log, x, top);
				addAt(l, k, x);
			}
			output(l);
			cout << endl;
			break;
		}
		case 3:
		{
			if (log[top-2] == 1)
			{
				int a = length(l);
				if (log[top - 1] == 1)
				{
					addHead(l, log[top]);
				}
				else if (log[top - 1] == a + 1)
				{
					addTail(l, log[top]);
				}
				else
				{
					addAt(l, log[top-1], log[top]);
				}
				top -= 3;
				output(l);
				cout << endl;
			}
			else if (log[top - 2] == 2)
			{
				int a = length(l);
				if (log[top - 1] == 1)
				{
					deleteHead(l);
				}
				else if (log[top - 1] == a)
				{
					deleteTail(l);
				}
				else
				{
					deleteAt(l, log[top-1]);
				}
				top -= 3;
				output(l);
				cout << endl;
			}
			break;
		}
		case 4:
		{
			if (log[top + 1] == 1)
			{
				int a = length(l);
				if (log[top + 2] == 1)
				{
					deleteHead(l);
				}
				else if (log[top + 2] == a)
				{
					deleteTail(l);
				}
				else
				{
					deleteAt(l, log[top + 2]);
				}
				top += 3;
				output(l);
				cout << endl;
			}
			if (log[top + 1] == 2)
			{
				int a = length(l);
				if (log[top + 2] == 1)
				{
					addHead(l, log[top]);
				}
				else if (log[top + 2] == a + 1)
				{
					 addTail(l, log[top]);
				}
				else
				{
					addAt(l, log[top + 2], log[top+3]);
				}
				top += 3;
				output(l);
				cout << endl;
			}
			break;
		}
		case 5:
		{
			int a = length(l);
			if (a == 0) //khi do dai cua day so la 0 thi khong lam gi het
			{
				break;
			}
			else
			{
				save(l);
			}
			break;
		}
		case 6:
		{
			//Xoa lich su lam viec
			for (int i = 0; i < dem; i++)
			{
				log[i] = INT_MIN;
			}
			int top = -1;
			int dem = 0;
			//Huy moi du lieu hien tai
			releaseList(l);
			//Nap lai day so input
			readFile(l);
			break;
		}
		case 7:
		{
			//Luu day so ket qua cua phien lam viec hien tai vao tap tin output
			writeFile(l);
			//Huy moi du lieu va giai phong bo nho
			releaseList(l);
			break;
		}
		case 8:
		{
			cout << "Command not found..." << endl;
			break;
		}
		}
	} while (n != 7);
}
