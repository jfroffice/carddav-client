<?php
    function array_to_xml($array,$level=0)
    {
	static $result="<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n";

        foreach($array as $k => $v)
	{
	    for($j=0;$j<$level;$j++)
		$result.="	";

	    if(is_numeric($k))
		array_to_xml($v,$level);
	    else
	    {
		$result.="<".htmlspecialchars($k);
		if($k=='resource')
		    $result.=" xmlns=\"urn:com.inf-it:configuration\"";
		$result.=">";
		if(is_array($v))
		{
		    $result.="\n";
		    array_to_xml($v,$level+1);
		    for($j=0;$j<$level;$j++)
			$result.="	";
		}
		else
		    $result.=htmlspecialchars($v);

		$result.="</".htmlspecialchars($k).">\n";
	    }
	}
	return $result;
    }
?>