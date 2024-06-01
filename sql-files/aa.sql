
--
-- Table structure for table `mail`
--

CREATE TABLE IF NOT EXISTS `mail` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `send_name` varchar(30) NOT NULL default '',
  `send_id` int(11) unsigned NOT NULL default '0',
  `dest_name` varchar(30) NOT NULL default '',
  `dest_id` int(11) unsigned NOT NULL default '0',
  `title` varchar(45) NOT NULL default '',
  `message` varchar(500) NOT NULL default '',
  `time` int(11) unsigned NOT NULL default '0',
  `status` tinyint(2) NOT NULL default '0',
  `zeny` int(11) unsigned NOT NULL default '0',
  `type` smallint(5) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM;

-- ----------------------------
-- Table structure for `mail_attachments`
-- ----------------------------

CREATE TABLE IF NOT EXISTS `mail_attachments` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `index` smallint(5) unsigned NOT NULL DEFAULT '0',
  `nameid` int(10) unsigned NOT NULL DEFAULT '0',
  `amount` int(11) unsigned NOT NULL DEFAULT '0',
  `refine` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `attribute` tinyint(4) unsigned NOT NULL DEFAULT '0',
  `identify` smallint(6) NOT NULL DEFAULT '0',
  `card0` int(10) unsigned NOT NULL DEFAULT '0',
  `card1` int(10) unsigned NOT NULL DEFAULT '0',
  `card2` int(10) unsigned NOT NULL DEFAULT '0',
  `card3` int(10) unsigned NOT NULL DEFAULT '0',
  `option_id0` smallint(5) NOT NULL default '0',
  `option_val0` smallint(5) NOT NULL default '0',
  `option_parm0` tinyint(3) NOT NULL default '0',
  `option_id1` smallint(5) NOT NULL default '0',
  `option_val1` smallint(5) NOT NULL default '0',
  `option_parm1` tinyint(3) NOT NULL default '0',
  `option_id2` smallint(5) NOT NULL default '0',
  `option_val2` smallint(5) NOT NULL default '0',
  `option_parm2` tinyint(3) NOT NULL default '0',
  `option_id3` smallint(5) NOT NULL default '0',
  `option_val3` smallint(5) NOT NULL default '0',
  `option_parm3` tinyint(3) NOT NULL default '0',
  `option_id4` smallint(5) NOT NULL default '0',
  `option_val4` smallint(5) NOT NULL default '0',
  `option_parm4` tinyint(3) NOT NULL default '0',
  `unique_id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `bound` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `enchantgrade` tinyint unsigned NOT NULL default '0',
    PRIMARY KEY (`id`,`index`)
) ENGINE=MyISAM;
