#include <iostream>
#include<vector>
#include<stdint.h>
#include<fstream>
using namespace std;

class Buffer {
	unsigned char* buf;
	public:
	Buffer();
	~Buffer();
};
Buffer::Buffer() {
	buf = new unsigned char[188];
}
Buffer::~Buffer() {
	delete [] buf;
}

typedef vector<uint8_t> SectionBuffer;//(188);
//typedef vector<Buffer> SectionBuffer;//(188);

template <size_t N>
void PsisiPack(SectionBuffer& buf, uintmax_t val) {
	int shift = ((N - 1) * 8);
	cout<<"Size of data type: "<<N<<endl;
	while (shift >= 0) {
		uintmax_t mask = (0xff << shift);
		buf.push_back(uint8_t((val & mask) >> shift));
		shift -= 8;
//		cout<<"Size of data type: "<<N<<endl;
//		buf.push_back(uint8_t(val));
   	}
}
/* May be used to pack tlv
template <typename TagType, typename ValueType>
void PsisiPackTlv(SectionBuffer& buf, TagType t, ValueType val) {
	PsisiPack<sizeof(TagType)>(buf, uintmax_t(t));
	PsisiPack<sizeof(std::size_t)>(buf, uintmax_t(sizeof(ValueType)));
	PsisiPack<sizeof(ValueType)>(buf, uintmax_t(val));
}*/

template <typename IntType>
void AppendField(SectionBuffer& buf, IntType val) {
	PsisiPack<sizeof(IntType)>(buf, uintmax_t(val));
}

void WriteBuffToFile(SectionBuffer& BtoF)
{
	vector<uint8_t>::iterator iter;
	ofstream SecFile ("SomeSection.sec", ios::out|ios::binary|ios::app);
  	cout<<"Size of the buffer is: "<<sizeof(BtoF)<<endl;
    string test = "This is a test string";	
	uint8_t testNum = 232;
	if (SecFile.is_open())
	{
		for(iter = BtoF.begin();iter!=BtoF.end();iter++)
		{		
		 	SecFile.write((const char*)&(*iter), sizeof(BtoF));
			cout<<"Value stored: "<<*iter<<endl;
		}
//		SecFile.write((const char*)test.c_str(), test.length());
//		SecFile.write(reinterpret_cast<const char*>(&testNum), sizeof(testNum)); 
//		SecFile.write((const char*)&testNum, sizeof(testNum)); 
		SecFile.close();
	}
	else cout<<"Unable to open file"<<endl;

}
int main() { 
  SectionBuffer bytes;
  vector<string> MyInts(2);
  vector<string>::iterator iter;
  for(iter=MyInts.begin();iter!=MyInts.end();iter++)
	{ 
		*iter = "Hello World";
	}
  AppendField(bytes, 0x70);   // appends sizeof(int) bytes
  AppendField(bytes, 176); // appends sizeof(unsigned long) bytes
  AppendField(bytes, 36510); // appends sizeof(int) bytes :p
  AppendField(bytes, (82 & 0xff)); // appends 1 byte
  AppendField(bytes,(70&0xff));
	for(iter=MyInts.begin();iter!=MyInts.end();iter++)
	{   
	   AppendField(bytes,(const char*)(*iter).c_str());   
     }  
  WriteBuffToFile(bytes);
  return 0;
}
