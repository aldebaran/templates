#ifndef @PROJECTNAME@IMPL_HPP_
#define @PROJECTNAME@IMPL_HPP_

#include <string>

#include <qi/session.hpp>
#include <@projectname@/@projectname@.hpp>

class @ProjectName@Impl : public @ProjectName@
{
public:
  // Add your public methods implementation
  // Yan can add everything you want in public here since only
  // methods comming from the interface will be export to user API
  @ProjectName@Impl(qi::SessionPtr& s);
  virtual ~@ProjectName@Impl();

  virtual void say(const std::string& mess);
  virtual void saySlowerButBetter(const std::string& mess);
  virtual int numberSay();

private:
  // Add your private methods
  // they will never be publish to user

private:
  // Add your private attribute
  qi::SessionPtr _session;
  int _numberOfSay;
  qi::AnyObject _tts;
};

#endif // !@PROJECTNAME@IMPL_HPP_
