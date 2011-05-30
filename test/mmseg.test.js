
/**
 * Module dependencies.
 */

var mmseg = require('mmseg')
  , should = require('should');

module.exports = {
  'test .version': function(){
    mmseg.version.should.match(/^\d+\.\d+\.\d+$/);
  }
};