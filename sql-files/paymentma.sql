/*
 Navicat Premium Data Transfer

 Source Server         : Meepo
 Source Server Type    : MySQL
 Source Server Version : 80300 (8.3.0)
 Source Host           : localhost:3306
 Source Schema         : ragnarok

 Target Server Type    : MySQL
 Target Server Version : 80300 (8.3.0)
 File Encoding         : 65001

 Date: 02/06/2024 13:49:50
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for paymentma
-- ----------------------------
DROP TABLE IF EXISTS `paymentma`;
CREATE TABLE `paymentma`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `souce` varchar(255) CHARACTER SET tis620 COLLATE tis620_thai_ci NULL DEFAULT NULL,
  `accid` int NOT NULL,
  `idname` varchar(255) CHARACTER SET tis620 COLLATE tis620_thai_ci NOT NULL,
  `value` int NOT NULL,
  `status` varchar(255) CHARACTER SET tis620 COLLATE tis620_thai_ci NULL DEFAULT NULL,
  `times` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = tis620 COLLATE = tis620_thai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of paymentma
-- ----------------------------
INSERT INTO `paymentma` VALUES (1, 'Ingame', 2000000, '1234561', 300, '0', '2024-06-02 13:34:44');

SET FOREIGN_KEY_CHECKS = 1;
