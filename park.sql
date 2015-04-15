/*
Navicat MySQL Data Transfer

Source Server         : localshot
Source Server Version : 50612
Source Host           : localhost:3306
Source Database       : park

Target Server Type    : MYSQL
Target Server Version : 50612
File Encoding         : 65001

Date: 2015-04-15 12:32:37
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for break_point
-- ----------------------------
DROP TABLE IF EXISTS `break_point`;
CREATE TABLE `break_point` (
  `bk_id` int(11) NOT NULL COMMENT '�յ��id',
  `posX` int(11) NOT NULL COMMENT '�յ��ڶ�Ӧ��ͼ�ϵ�X����',
  `posY` int(11) NOT NULL COMMENT '�յ��ڶ�Ӧ��ͼ�ϵ�Y����',
  `MAP_id` int(11) NOT NULL COMMENT '�յ����ڵ�ͼ��id',
  PRIMARY KEY (`bk_id`),
  KEY `MAP_id` (`MAP_id`),
  CONSTRAINT `FK_BREAK_POINT_MAP` FOREIGN KEY (`MAP_id`) REFERENCES `map` (`MAP_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for map
-- ----------------------------
DROP TABLE IF EXISTS `map`;
CREATE TABLE `map` (
  `posZ` int(11) NOT NULL,
  `PARK_id` int(11) NOT NULL,
  `MAP_url` varchar(255) NOT NULL,
  `MAP_id` int(11) NOT NULL,
  PRIMARY KEY (`MAP_id`),
  KEY `PARK_id` (`PARK_id`),
  CONSTRAINT `FK_MAP_PARK` FOREIGN KEY (`PARK_id`) REFERENCES `park` (`PARK_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for park
-- ----------------------------
DROP TABLE IF EXISTS `park`;
CREATE TABLE `park` (
  `PARK_id` int(11) NOT NULL COMMENT 'ͣ����id',
  `name` varchar(255) NOT NULL COMMENT 'ͣ����������',
  `price` double NOT NULL DEFAULT '0' COMMENT '�շѱ�׼ /ÿСʱ',
  `allpos` int(11) NOT NULL COMMENT '��λ����',
  `emppos` int(11) NOT NULL COMMENT '�ճ�λ����',
  `state` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`PARK_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for point
-- ----------------------------
DROP TABLE IF EXISTS `point`;
CREATE TABLE `point` (
  `POINT_id` int(11) NOT NULL COMMENT '�ڵ��id',
  `posX` int(11) NOT NULL DEFAULT '0' COMMENT '�ڵ��X����',
  `posY` int(11) NOT NULL DEFAULT '0' COMMENT '�ڵ��Y����',
  `posZ` int(11) NOT NULL DEFAULT '0' COMMENT '�ڵ��Z����������������Ӧ���ͣ����',
  `PARK_id` int(11) NOT NULL COMMENT '�ڵ�����ͣ������id',
  `state` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'stateΪfalseʱΪ��ռ�û�δ����,ΪtrueʱΪδ��ռ�û��Ѽ���',
  `type` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'typeΪtrueʱΪ�û��ڵ�,ΪfalseʱΪ��λ�ڵ�',
  `todo` int(1) NOT NULL DEFAULT '1',
  `Mac` char(17) NOT NULL,
  PRIMARY KEY (`POINT_id`),
  KEY `PARK_id` (`PARK_id`),
  CONSTRAINT `FK_POINT_PARK` FOREIGN KEY (`PARK_id`) REFERENCES `park` (`PARK_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `USER_id` int(11) NOT NULL COMMENT '�û�id',
  `USERPOINT_id` int(11) NOT NULL COMMENT '�û��ֳֽڵ��id',
  `carPOINT_id` int(11) NOT NULL COMMENT '������λ���Ϸ��ڵ��id',
  `startTime` datetime NOT NULL,
  `PARK_id` int(11) NOT NULL COMMENT '�û�����ͣ������id���������',
  `state` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`USER_id`),
  KEY `PARK_id` (`PARK_id`),
  KEY `USERPOINT_id` (`USERPOINT_id`),
  KEY `carPOINT_id` (`carPOINT_id`),
  CONSTRAINT `FK_USER_PARK` FOREIGN KEY (`PARK_id`) REFERENCES `park` (`PARK_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `FK_USER_POINT` FOREIGN KEY (`USERPOINT_id`) REFERENCES `point` (`POINT_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
