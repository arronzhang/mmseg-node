var mmseg = require("./build/Release/mmseg.node").mmseg;

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

module.exports.uniq =function(arr) {
	var u = {}, a = [];
	for(var i = 0, l = arr.length; i < l; ++i){
		if(u.hasOwnProperty(arr[i]))
			continue;
		a.push(arr[i]);
		u[arr[i]] = 1;
	}
	return a;
}
