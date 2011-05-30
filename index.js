var mmseg = require("./build/default/mmseg.node").mmseg;

module.exports.open =  function(file) {
	return new mmseg(file);
};
