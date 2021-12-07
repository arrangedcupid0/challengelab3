#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//i hate to turn in non-working code, but i have tried literally everything i know how and i'm still dead in the water.
	//i wish i was better at this, and i'm sorry i'm not

	ifstream file("encoded_apollo.jpg", ios::in | ios::out | ios::binary);
//	fstream file("binary_apollo.bin", ios::in | ios::out | ios::binary);

//	char tmp;
//	while(!image.eof())
//	{
//		tmp = image.get();
//		file.put(tmp);
//	}
//	image.close();

	char buff[8+1]{0};

//	for(auto i(0); i < file.gcount(); i++)
//	{
//		cout << "[";
//		cout << hex << setfill('0') << setw(2) << (0xFF & buff[i]);
//		cout << "]";
//	}
//	ifstream file("binary_apollo.bin", ios::in | ios::binary);
	int count = 0;
	char bytes[8];
//	file.seekg(2); 
//	char x;
//	file.read((&x), 1);
//	cout << x << endl;
	int ep = 0;
	int it = 1;
	while(file.read(buff, (8 * it)))
	{ 
		it++;
//		for(int i = 0; i < 8; i++)
//		{
//			cout << "made" << bytes[i] << " ";
//		}
//		cout << " " << endl;
		if(bytes[count] == '!')
		{
			if(ep == 3)
			{
				ep = 0;
				while(file.get(bytes[count]))
				{
				if(count == 7)
				{
					int other = 0;
					string temp;
					while(count > -1)
					{
						temp += bytes[other];
						other++;
						count--;
					}
				}
				count++;
				}
			} else {
				ep++;
			}
		}
	}
	return 0;
}
