
-	script	Payment	 -1,{

OnInit:
	
	.bonusitem = 1;		// ไปแก้ของกับจำนวนด้านล่าง
	.top_up_coin = 6898;
	setarray .stairbonus,100;
	setarray .stairval,1;
	
	while (1)
	{
		query_sql "SELECT `souce`,`value`,`accid` FROM `paymentma` WHERE `status` = '0'",.souce$,.pay_amount,.pay_user_id;
		sleep 1000;
		if (getarraysize(.souce$) > 0) {
			for (set .i,0; .i < getarraysize(.souce$); set .i,.i+1) {
				
				if(attachrid(.pay_user_id[.i]))
				{
					// check userid
					query_sql("SELECT `userid` FROM `login` WHERE `account_id` = '"+.pay_user_id[.i]+"'",@uid$);
					
					.@realget = .pay_amount[.@i] * 10;
					for(.@u = getarraysize(.stairbonus); .@u > 0; .@u--) {
						if(.pay_amount[.@i] > .stairbonus[.@u-1]) {
							.@pos = .@u-1;
							break;
						}
					}
					.@realget += .@realget * .stairval / 100 ;
					if(.pay_amount[.i] > 0){
						//dispbottom "==============================================";
						//dispbottom "[ Payment Server ] คุณได้รับ " + callfunc("F_InsertComma",.@realget) + " Cash ปัจจุบันมี "+ callfunc("F_InsertComma",#CASHPOINTS);
						set #CASHPOINTS,(#CASHPOINTS + .@realget);
					}
					dispbottom "==============================================";
					dispbottom "[ Payment Server ] คุณได้รับ " + callfunc("F_InsertComma",.@realget) + " Cash ปัจจุบันมี "+ callfunc("F_InsertComma",#CASHPOINTS);
					announce "ท่าน ["+strcharinfo(0)+"] เติมเงินจำนวน ["+.pay_amount[.i]+"] เรียบร้อยแล้ว",bc_all;
					query_sql "UPDATE `paymentma` SET `status` = '2' WHERE `souce` = '" + .souce$[.i]+"'";
					
					// Bonus Item Refil
					if(.bonusitem) {
							set .@week,0;
							
							setarray .@val[0],10;							
							setarray .@itembonus,.top_up_coin;
							for(.@g=0; .@g<getarraysize(.@val); .@g++) {
								setd "#cash_collect_w"+.@week+"_"+.@val[.@g],getd("#cash_collect_w"+.@week+"_"+.@val[.@g])+.pay_amount[.i];
								.@dot[.@g] = getd("#cash_collect_w"+.@week+"_"+.@val[.@g])/.@val[.@g];
								setd "#cash_collect_w"+.@week+"_"+.@val[.@g],getd("#cash_collect_w"+.@week+"_"+.@val[.@g])%.@val[.@g];
							}
							/*
							for(.@s=0;.@s<getarraysize(.@dot);.@s++) {
								//if(.@itembonus[.@s] == 12411) .@dot[.@s] *= 3;
								if(.@dot[.@s]) {
									getitem .@itembonus[.@s],.@dot[.@s];
									if (.@itembonus[.@s] ==  6544) {
										getitem 40916,.@dot[.@s];
									}
									if (.@itembonus[.@s] ==  12411) {
										getitem 12412,.@dot[.@s];
									}
								}
							}
							*/
							//announce "ท่าน ["+strcharinfo(0)+"] ได้รับ ["+getitemname(.@itembonus[.@s])+"] จำนวน "+.@dot[.@s]+"ชิ้น จากโปรโมชั่นเติมเงินเรียบร้อยแล้ว",bc_all;

					}
					//End BOnus
					detachrid;	
				}
				//deletearray .cash_bonus_item_id[0],getarraysize(.cash_bonus_item_id);
				//deletearray .cash_bonus_item_amount[0],getarraysize(.cash_bonus_item_amount);
			}
			deletearray .souce$[0],getarraysize(.souce$);
			deletearray .pay_amount[0],getarraysize(.pay_amount);
			deletearray .pay_user_id[0],getarraysize(.pay_user_id);

		}
		sleep 5000;
	}
	end;

}

-	script	commandpayment	-1,{
OnInsertSQL:
	if(!.@atcmd_numparameters) {
		dispbottom "วิธีใช้คือ @donate id amount";
		end;
	}
	.@userid$ = .@atcmd_parameters$[0];
	.@amount = atoi(.@atcmd_parameters$[1]);
	query_sql("SELECT `userid`,`account_id` FROM `login` WHERE `userid` LIKE '"+.@userid$+"'",.@uid$,.@uaid);
	if(!.@uaid) {
		dispbottom "ID ไม่ถูกต้อง";
		end;
	}
	dispbottom "เติมเงิน ID:"+.@uid$+" จำนวน :"+.@amount+" บาท เรียบร้อยแล้ว";
	query_sql("INSERT INTO paymentma (souce,accid,idname,value,status) VALUES ('ingame by "+strcharinfo(0)+"',"+.@uaid+",'"+.@uid$+"','"+.@amount+"','0')");
	end;
Oninit:
	bindatcmd "@donate",strnpcinfo(0)+"::OnInsertSQL",99,99;
	end;
}