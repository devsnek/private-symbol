#include <v8.h>
#include <node.h>

using v8::Local;
using v8::FunctionCallbackInfo;
using v8::Object;
using v8::Symbol;
using v8::Private;
using v8::String;
using v8::Value;
using v8::Function;
using v8::Isolate;
using v8::Context;

void PrivateSymbol(const FunctionCallbackInfo<Value>& args) {
  Local<Private> p = Private::New(args.GetIsolate(), args[0].As<String>());
  args.GetReturnValue().Set(*reinterpret_cast<Local<Value>*>(&p));
}

void Init(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  Local<Context> context = isolate->GetCurrentContext();
  exports->Set(context,
               String::NewFromUtf8(isolate, "private", v8::NewStringType::kNormal).ToLocalChecked(),
               Function::New(context, PrivateSymbol).ToLocalChecked()).ToChecked();
}

NODE_MODULE(private, Init)
