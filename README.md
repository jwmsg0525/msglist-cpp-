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

 <h2>Example</h2>
 * Push 3, 6, 7, 5, 4, 9, 8, 4, 7
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
</pre>

 * Insert 8 at 5th position
<pre>
msglist.insert(5, 8);
</pre>

 * Insert 23 at 2th from 5th position (insert at 7)
<pre>
msglist.insert(2, 5, 23);
<pre>

 * Find data with position 3th (begin at 0)
<pre>
cout&lt;&lt;msglist.find_node(3)-&gt;data&lt;&lt;endl;

return >> 7
<pre>

 * Find data with position 3th (begin at 7)
<pre>
cout&lt;&lt;msglist.find_node(7,3)-&gt;data&lt;&lt;endl;
</pre>

 * Find position with first found data (7) (begin at 0)
<pre>
cout&lt;&lt;msglist.find_position(7)&lt;&lt;endl;
</pre>

 * Find position with first found data (3) (begin at 6)
<pre>
cout&lt;&lt;msglist.find_position(6, 3)&gt;&gt;endl;
</pre>

 * Remove last data(POP)
<pre>
msglist.remove();
</pre>

 * Remove position 4th
<pre>
msglist.remove_p(4);
</pre>

 * Remove position 4th (begin at 3)
<pre>
msglist.remove_p(3, 4);
</pre>

 * Remove first found data (5) (begin at 0)
<pre>
msglist.remove_d(5);
</pre>

 * Remove first found data (9) (begin at 6)
<pre>
msglist.remove_d(6,9);
</pre>

 * Modify last data to 8
<pre>
msglist.modify(8)
</pre>

 * Modify position 7th data to 9
<pre>
msglist.modify_p(7,9);
</pre>

 * Modify position 3th (begin at 4) to 8
<pre>
msglist.modify_p(4, 3, 8);
</pre>

 * Modify first found data 3 to 9
<pre>
msglist.modify_d(3,9);
</pre>

 * Modify first found data 7 (begin at 8) to 10
<pre>
msglist.modify_d(8, 7, 10);
</pre>
