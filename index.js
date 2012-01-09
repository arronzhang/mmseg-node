var mmseg = require("mmseg").mmseg;

module.exports.open =  function(file) {
	return new mmseg(file);
};

/*
*
* Clean
*
* $param array ar
* $return array ar. Only return number, letter, chinese word
*
*/
module.exports.clean =function(ar) {
	if( ar && ar.length ){
		var a = [];
		for (var i = 0, l = ar.length; i < l; i++) {
			if( /^[\u4e00-\u9fa5\da-zA-Z]+$/.test(ar[i]) ) a.push(ar[i]);
		};
		ar = a;
	}
	return ar;
};

module.exports.uniq =function(ar) {
	var a = [];
	var l = ar.length;
	for(var i=0; i<l; i++) {
		for(var j=i+1; j<l; j++) {
			// If ar[i] is found later in the array
			if (ar[i] === ar[j])
				j = ++i;
		}
		a.push(ar[i]);
	}
	return a;
}
