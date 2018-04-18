<h1> MsgList </h1>

 * this is a List (now It works for "int")
 * It works int C++ language
 * 2018-14-18 15:00 (KST) / 2018-14-18 06:00 (UTC) It can build.

<h2> Useage </h2>

 * add header
<pre>

 * msglist/msglist/msglist.hpp
 * msglist/msglist/msglist.cpp

</pre>

 * Define MsgList
<pre>
MsgList msglist;
</pre>

 * Close MsgList
<pre>
~msglist;
</pre>

 * Example
	Push 3, 6, 7, 5, 4, 9, 8, 4, 7
<pre>
MsgList msglist;
msglist.insert(3);
msglist.insert(6);
msglist.insert(7);
msglist.insert(5);
msglist.insert(4);
msglist.insert(9);
msglist.insert(8);
msglist.insert(4);
msglist.insert(7);
<pre>

