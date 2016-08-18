#include <iostream> 
#include <qi/applicationsession.hpp>

int main(int argc, char** argv)
{
  qi::ApplicationSession app(argc, argv);
  app.start();

  qi::SessionPtr session = app.session();
  qi::AnyObject tts = session->service("myservice");

  std::cout << "Say hello word. "<< std::endl << std::endl;
  tts.call<void>("sayHelloWord");

  std::cout << "Get head joint values: "<< std::endl ;
  std::vector<std::string> jointNames;
  jointNames.push_back("HeadYaw");
  jointNames.push_back("HeadPitch");

  std::vector<float> jointValues = tts.call<std::vector<float> >("getJointValues", jointNames);
  for (unsigned int i = 0; i < jointNames.size(); i++)
    std::cout << jointNames[i] << ": "<< jointValues[i] << std::endl;

  session->close();

  return 0;

}
