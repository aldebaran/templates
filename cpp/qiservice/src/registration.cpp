#include <qi/anymodule.hpp>
#include <@projectname@/@projectname@.hpp>

#include "@projectname@impl.hpp"

// First way to register your service into the type system
// hard one but more flexible (add some dynamic doc)
static bool _qiregister@ProjectName@()
{
  qi::ObjectTypeBuilder<@ProjectName@> builder;
  builder.setThreadingModel(qi::ObjectThreadingModel_MultiThread);

  // Advertise methods
  qi::MetaMethodBuilder mmb;
  mmb.setName("say");
  mmb.appendParameter("mess", "Your incredible method parameter description");
  mmb.setReturnDescription("Your fantastic method return description");
  mmb.setDescription("Your awesome method description");
  builder.advertiseMethod(mmb, &@ProjectName@::say);
  builder.advertiseMethod("saySlowerButBetter", &@ProjectName@::saySlowerButBetter);
  builder.advertiseMethod("numberSay", &@ProjectName@::numberSay);

  // Advertise signals
  builder.advertiseSignal("onSayMessage", &@ProjectName@::onSayMessage);

  // Advertise properties
  builder.advertiseProperty("message", &@ProjectName@::message);

  builder.registerType();
  return true;
}
static bool __qi_registration@ProjectName@ = _qiregister@ProjectName@();

// OR the second way easier but you cannot specified documentation or whatever
// QI_REGISTER_MT_OBJECT(@ProjectName@, say, saySlowerButBetter, numberSay, onSayMessage, message);
