# php-ext
This is a php extensions, I will continue update and share it for everyone. Currently it only support PHP 7.4 or greater than 7.4.

## VThread 

VThread is extension support for you run code PHP in environment C (native code). It's best if your function need resolve a lots of logic and take a long time for finish. That time is you need use VThread to optimize process.

### How to install? 

First step you need download file `.so` on folder `./vthread` after that add this line into your `php.ini` file: 
    `extension="/path/to/file.so"`

### How to check working? 
Create a new file and use phpinfo to check

![alt text](https://github.com/steveleetn91/php-ext/blob/dev/document/phpinfo.PNG?raw=true)


### Code for test [nukethread]

![alt text](https://github.com/steveleetn91/php-ext/blob/dev/document/vthread.PNG?raw=true)

This function same with Fibers, I mean callback will execute in child thread but it's keep asyn. So why we need use it? 
When you implement if appear errors then main process keep continue and only stop on child process. And it'll support execute
your function callback on native code.

On PHP:

```
        <?php

        try {
            
            nukethread(function () {
                printf("Done ");
                sleep(1);
            });
        }catch(\Exception $e) {
            print_r($e->getMessage());
        }

        ?>
```

### Code for test [nukethreadOnlyThread]


It'll support execute your function callback on native code and only one thread.

On PHP:

```
        <?php

        try {
            
            echo nukethreadOnlyThread(function () {
                return rand(1,999999999999999999);
            });
        }catch(\Exception $e) {
            print_r($e->getMessage());
        }

        ?>
```

# Issue 

If you need anything, please create new issue `https://github.com/steveleetn91/php-ext/issues`. 

One more thing if you enjoy and wanna I continue made extensions support for PHP, so let's me star for this repository.


