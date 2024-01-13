# trnsl
This is a terminal utility written in C++ for dealing with human-adjusted machine translating of captions using automated services like Google Translate, DeepL Translate and ChatGPT by translating it chunk-by-chunk. 
This currently was made only to work correctly with subtitles in this format:

```
0:00:00.040,0:00:05.680
French spelling sucks. We all know this already. 
It's inconsistent. It's unpredictable...

0:00:05.680,0:00:08.560
At times it's ugly, at 
others it's just ridiculous.

0:00:08.560,0:00:11.640
And the number one offender: silent graphemes.

0:00:11.640,0:00:13.920
Every other letter and accent and verb ending
```

And not this format (.vtt / WebVTT):
```
0:00:00.040 --> 0:00:05.680
French spelling sucks. We all know this already. 
It's inconsistent. It's unpredictable...

0:00:05.680 --> 0:00:08.560
At times it's ugly, at 
others it's just ridiculous.

0:00:08.560 --> 0:00:11.640
And the number one offender: silent graphemes.

0:00:11.640 --> 0:00:13.920
Every other letter and accent and verb ending
```

But with a simple patch (by changing all the 24s to a 28s it should work perfectly), with other simple patches you can it make it work with other plain text .

![image](https://github.com/codemanticism/trnsl/assets/67880895/c68370e5-3d74-4231-a563-962301cb5843)

To use you simply type in the file name while whatever Terminal you are using is in the same directory as that executable and then type ```trnsl.exe [FILENAME] [MAXIMUM AMOUNT OF CHARACTERS A CHUNK CAN HAVE]``` in the Windows Terminal.

After the program displaying all chunks, don't input anything in the terminal yet.
Then you create a file in your favourite text editor, then apply machine translation in all of those chunks and copy all the results into the text file, make sure to space everything properly, the two captions must line up perfectly.
Then you go back to the terminal and simply type the name of the file you copied all those translations to and then type whatever name you want for the new translated version with all the timestamps that will be created after you press Enter / Return.
