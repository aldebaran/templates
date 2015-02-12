// THIS FILE WILL BE GENERATE ONE DAY

#include <string>

#include <qi/types.hpp>

#include <qi/anyobject.hpp>
#include <qi/type/proxysignal.hpp>
#include <qi/type/proxyproperty.hpp>

#include <@projectname@/@projectname@.hpp>

class @ProjectName@Proxy : public qi::Proxy, public @ProjectName@
{
public:
  @ProjectName@Proxy(qi::AnyObject obj)
    : qi::Proxy(obj)
  {
    // Add your own signals proxy here
    qi::makeProxySignal(onSayMessage, obj, "onSayMessage");

    // Add your own properties proxy here
    qi::makeProxyProperty(message, obj, "message");
  }


  // Add your public methods proxy
  void say(const std::string& mess)
  {
    _obj.call<void>("say", mess);
  }

  void saySlowerButBetter(const std::string& mess)
  {
    _obj.call<void>("saySlowerButBetter", mess);
  }

  int numberSay()
  {
    return _obj.call<int>("numberSay");
  }
};

QI_REGISTER_PROXY_INTERFACE(@ProjectName@Proxy, @ProjectName@);
