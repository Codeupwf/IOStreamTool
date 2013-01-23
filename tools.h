#include <fstream>
#include <string>
#include <iostream>

using namespace std;

namespace tools
{
	class FileStream
	{
	public:
		FileStream(const string& strFileName)
		{
			m_strFileName = strFileName;
			m_file.open(m_strFileName.c_str());
			if(!m_file)
			{
				std::cout<<"open file error, filename is "<<strFileName<<std::endl;
				return;
			}
		}
		~FileStream()
		{
			m_file.close();
			return;
		}

		fstream& cout()
		{
			return m_file;
		}

		fstream& cin()
		{
			return m_file;
		}

	private:
		string m_strFileName;
		fstream m_file;
	};
}

#define OPEN_FILE(x,index) tools::FileStream file##index(x)
#define TOOLS_CIN(index) (file##index.cin())
#define TOOLS_COUT(index) (file##index.cout())
