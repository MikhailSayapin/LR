#include <boost/filesystem.hpp>
#include <map>
#include <iostream>

using namespace boost::filesystem;

std::map<std::string, std::map<int, std::pair<int, int> > > report;

void dirObxod(std::string path, size_t substr_skip)
{
	for (const directory_entry &x : directory_iterator(path))
	{
		if (boost::filesystem::is_directory(x.path()))
			dirObxod(x.path().string(), substr_skip);
		else
		{
			std::string fileName = x.path().filename().string();
			int n1, n2;
			try
			{
				if (fileName.find("balance_") != 0)
					continue;
				if (fileName[16] != '_')
					continue;
				n1 = std::stoi(fileName.substr(8, 8));
				n2 = std::stoi(fileName.substr(17, 8));
				if (fileName.substr(25) != ".txt")
					continue;
				//std::cout << x << ' ' << n << std::endl;
				std::cout << path.substr(substr_skip) << ' ' << fileName << std::endl;
				std::string broker = path.substr(substr_skip);
				report[broker][n1].first++;
				report[broker][n1].second = std::max(report[broker][n1].second, n2);
			}
			catch (std::exception &e)
			{
				continue;
			}
		}
	}
}

int main(int argc, char **argv)
{
	std::string dirpath;
	if (argc == 2)
	{
		dirpath = std::string(argv[1]);
	}
	else
	{
		dirpath = "D:\\Projects\\lab-05-boost-filesystem-master\\misc\\ftp";
	}
	dirObxod(dirpath, dirpath.length() + 1);
	for (const auto &x : report)
	{
		for (const auto &y : x.second)
		{
			std::cout << "broker:" << x.first << " account:" << y.first << " files:" << y.second.first
				<< " lastdate:" << y.second.second << std::endl;
		}
	}
}
