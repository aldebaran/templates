#include <qi/anymodule.hpp>
#include "@projectname@impl.hpp"

@ProjectName@Impl::@ProjectName@Impl(qi::SessionPtr& s)
  : _session(s)
  , _numberOfSay(0)
{
  try
  {
    _tts = _session->service("ALTextToSpeech");
  }
  catch (std::exception& e)
  {
    // do what ever you want if the service doesn't exist
    std::cout << "Error: " << e.what() << std::endl;
  }
}

@ProjectName@Impl::~@ProjectName@Impl()
{
}

void @ProjectName@Impl::say(const std::string& mess)
{
  try
  {
    // call ALTextToSpeech say with mess
    _tts.call<void>("say", mess);

    // store on the property the value of the message say
    message.set(mess);
    // send a signal with the number of say play
    onSayMessage(_numberOfSay);
  }
  catch (std::exception& e)
  {
    // do what ever you want when call failed
    // you could for exemple trying to reconnect to the service.
    std::cout << "Error: " << e.what() << std::endl;
  }
}

void @ProjectName@Impl::saySlowerButBetter(const std::string& mess)
{
  try
  {
    // get tts object (this is better since tts can be disconnected
    // at anytime since you init it in the Ctor
    // BUT it's slower
    qi::AnyObject tts = _session->service("ALTextToSpeech");

    // call ALTextToSpeech say with mess
    tts.call<void>("say", mess);

    // store on the property the value of the message say
    message.set(mess);
    // send a signal with the number of say play
    onSayMessage(_numberOfSay);
  }
  catch (std::exception& e)
  {
    // do what ever you want when call failed
    std::cout << "Error: " << e.what() << std::endl;
  }
}

int @ProjectName@Impl::numberSay()
{
  return _numberOfSay;
}

// Specified to the type system that @ProjectName@Impl is the implementation of @ProjectName@ API
QI_REGISTER_IMPLEMENTATION(@ProjectName@, @ProjectName@Impl);

// Create a factory. It will allow the type system to create a AnyObject of your service
// If you are more than one factory put them here
void register@ProjectName@(qi::ModuleBuilder* mb)
{
  mb->advertiseFactory<@ProjectName@Impl, qi::SessionPtr>("AL@ProjectName@");
}
QI_REGISTER_MODULE("@projectname@", &register@ProjectName@);
