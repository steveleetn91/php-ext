#include <iostream>
#include <phpcpp.h>
#include <pthread.h>
#include <string>
/**
 *  tell the compiler that the get_module is a pure C function
 */

extern "C" {
     struct callback_struct {
        Php::Value callback;
        int isWork;
    };
    void *callback(void *arguments){
        struct callback_struct *args =  (struct  callback_struct *)arguments;
        
        if (!args->callback.isCallable()) {
            throw Php::Exception("Not a callable type.");
            // printf("Error");
            // return NULL;
        }
        args->callback();
        pthread_exit(NULL);
        return NULL;
        
    }
    Php::Value nukethread(Php::Parameters &params)
    {
        
        // check whether the parameter is callable
        if (!params[0].isCallable()) throw Php::Exception("Not a callable type.");
            
        // perform the callback
        struct callback_struct app;
        app.callback = params[0];
        app.isWork = 1;
        pthread_t thread;
        int status;
        status = pthread_create(&thread, NULL, &callback,(void *)&app); 
        pthread_join(thread, NULL);
        return NULL;
    }

    Php::Value nukethreadOnlyThread(Php::Parameters &params)
    {
        
        // check whether the parameter is callable
        if (!params[0].isCallable()) throw Php::Exception("Not a callable type.");
        
        return params[0]();

    }

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() 
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("vthread","Version 1.0. Author: SteveLee - Le Minh Hoang");
        // @todo    add your own functions, classes, namespaces to the extension
        extension.add<nukethread>("nukethread", {
            Php::ByVal("addFunc", Php::Type::Callable)
        });
        extension.add<nukethreadOnlyThread>("nukethreadOnlyThread", {
            Php::ByVal("addFunc", Php::Type::Callable)
        });
        // return the extension
        return extension;
    }
}
