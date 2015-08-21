#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

int main ()
{
  int timeYear, timeMonth, timeDay, timeh, timem, times, testNumber;
  char  sensor[4];
  float objTemp;
  float chamberTemp, lastAbsTemp, lastAbsLpWidthDcpa, lastAbsLpWidthDca;

  std::string filename("2015.07.13.11.52.59_002_TV_-100.00_-99.00_0.00_Laser");
  std::istringstream parse;
  parse.str(filename);
  std::string temp;

  //get year
  std::getline(parse, temp, '.');
  timeYear = strtoul(temp.data(), 0, 10);
  std::cout << timeYear << "\n";

  //get month
  getline(parse, temp, '.');
  timeMonth = strtoul(temp.data(), 0, 10);
  std::cout << timeMonth << "\n";

  //get day
  getline(parse, temp, '.');
  timeDay = strtoul(temp.data(), 0, 10);
  std::cout << timeDay << "\n";

  //get hour
  getline(parse, temp, '.');
  timeh = strtoul(temp.data(), 0, 10);
  std::cout << timeh << "\n";

  //get minute
  getline(parse, temp, '.');
  timem = strtoul(temp.data(), 0, 10);
  std::cout << timem << "\n";

  //get seconds
  getline(parse, temp, '_');
  times = strtoul(temp.data(), 0, 10);
  std::cout << times << "\n";

  //get test number
  getline(parse, temp, '_');
  testNumber = strtoul(temp.data(), 0, 10);
  std::cout << testNumber << "\n";

  //get sensor type
  getline(parse, temp, '_');
  strcpy(sensor, temp.data());
  sensor[2] = 0;
  std::cout << sensor << "\n";

  //get objective temp
  getline(parse, temp, '_');
  objTemp = (float)strtod(temp.data(), 0);
  std::cout << objTemp << "\n";

  //get last ABS temp
  getline(parse, temp, '_');
  lastAbsTemp = (float)strtod(temp.data(), 0);
  std::cout << lastAbsTemp << "\n";

  //get chamber temp
  getline(parse, temp, '_');
  chamberTemp = (float)strtod(temp.data(), 0);
  std::cout << chamberTemp << "\n";

  // finally, we get the laser power pre-amp and amp values
  // however, we have to handle backwards compatibility with old filenames
  // that do not have preamp/amp values, so we have to determine what to do
  // with the next parsed string
  getline(parse, temp, '_');

  // old file format ends with the type of frame, either Laser or Dark
  if ((temp.compare("Laser") == 0) || (temp.compare("Dark") == 0))
  {
    // if it's the old format, then we have no pre-amp/amp values
    // so we store impossible power values to signify we don't have them
    lastAbsLpWidthDcpa = (float)-999.0;
    lastAbsLpWidthDca = (float)-999.0;
  }
  // new file format ends with laser power pre-amp followed by amp
  else
  {
    // if it's the new format, then the string we just parsed is actually
    // the pre-amp value
    lastAbsLpWidthDcpa = (float)strtod(temp.data(), 0);

    // which means the last string is the amp value
    getline(parse, temp, '_');
    lastAbsLpWidthDca = (float)strtod(temp.data(), 0);
  }
  std::cout << lastAbsLpWidthDcpa << "\n";
  std::cout << lastAbsLpWidthDca << "\n";

  return 0;
}
