/*
** Author(s):
**  - John Do <jdo@aldebaran.com>
**
** Copyright (C) 2015 Aldebaran Robotics
*/

#ifndef @PROJECTNAME@_HPP_
#define @PROJECTNAME@_HPP_

#include <string>

#include <qi/anyobject.hpp>
#include <qi/property.hpp>
#include <qi/session.hpp>
#include <qi/signal.hpp>

#include <@projectname@/api.hpp>

class @PROJECTNAME@_API @ProjectName@
{
public:
  // Ctors
  @ProjectName@()
  {
  }
  // Dtors
  virtual ~@ProjectName@()
  {
  }

  // Public Methods
  virtual void say(const std::string& mess) = 0;
  virtual void saySlowerButBetter(const std::string& mess) = 0;
  virtual int numberSay() = 0;

public:
  // Public Properties
  qi::Property<std::string> message;

  // Public Signals
  qi::Signal<int> onSayMessage;
};

// Should be add into your namespace if you have one
// otherwise keep it like this
typedef qi::Object<@ProjectName@> @ProjectName@Ptr;

QI_TYPE_INTERFACE(@ProjectName@);

#endif // !@PROJECTNAME@_HPP_
