var mmseg = require("mmseg");
var q = mmseg.open('/Users/hidden/project/zhejie/zhejie.com/dictdata');

function run () {
	//var ar = q.segmentSync("13家店通用！9元超低价享404元维娜姿瘦身养生套餐:速效纤体排毒（原价298元30分钟）+美式头面部舒压疗法 原价58（约15分钟）+背部紧致修身（原价48元15分钟）+全身脂肪测评1次！男女通用！商家承诺绝无任何隐性消费！国际专业减重连锁，让身体回复轻盈呼吸！繁體測試測試");
	var ar = q.complexSegmentSync("13家店通用！9元超低价享404元维娜姿瘦身养生套餐:速效纤体排毒（原价298元30分钟）+美式头面部舒压疗法 原价58（约15分钟）+背部紧致修身（原价48元15分钟）+全身脂肪测评1次！男女通用！商家承诺绝无任何隐性消费！国际专业减重连锁，让身体回复轻盈呼吸！繁體測試測試");
	// ar = mmseg.uniq(mmseg.clean(ar));
	//console.log(ar && ar.join(","));
}

function runGroup () {
	for (var i = 0; i < 1000; i++) {
		run();
	};
}

setInterval( runGroup, 1000 );
//run();
//run();
