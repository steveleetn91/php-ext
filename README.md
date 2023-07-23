# php-ext
This is an list php extension to support for PHP, I will continue update and share it for everyone. Currently it only support PHP 8.0 or greater than 8.0.

## VThread 

VThread is extension support for you run code PHP in environment C (native code). It's best if your function need resolve a lots of logic and take a long time for finish. That time is you need use VThread to optimize process.

### How to install? 

First step you need download file `.so` on folder `./vthread` after that add this line into your `php.ini` file: 
    `extension="/path/to/file.so"`

### How to check working? 
Create a new file and use phpinfo to check

![alt text](https://github.com/steveleetn91/php-ext/document/image.jpg?raw=true)


# Issue 

If you need anything, please create new issue `https://github.com/steveleetn91/php-ext/issues`


