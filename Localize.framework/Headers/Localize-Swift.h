// Generated by Apple Swift version 3.0.2 (swiftlang-800.0.63 clang-800.0.42.1)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import UIKit;
@import CoreGraphics;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

/**
  Is a pricipal class, contents all logic to localize your keys
  read json and determinate all configurations.
*/
SWIFT_CLASS("_TtC8Localize8Localize")
@interface Localize : NSObject
/**
  Shated instance
*/
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) Localize * _Nonnull shared;)
+ (Localize * _Nonnull)shared;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
/**
  Localize a string using your JSON File
  If the key is not found return the same key
  That prevent replace untagged values

  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key tableName:(NSString * _Nullable)tableName;
/**
  Localize a string using your JSON File
  That replace all % character in your string with replace value.
  \param value The replacement value


  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key replace:(NSString * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
/**
  Localize a string using your JSON File
  That replace each % character in your string with each replace value.
  \param value The replacement values


  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key values:(NSArray * _Nonnull)values tableName:(NSString * _Nullable)tableName;
/**
  Localize string with dictionary values
  Get properties in your key with rule :property
  If property not exist in this string, not is used.
  \param value The replacement dictionary


  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key dictionary:(NSDictionary<NSString *, NSString *> * _Nonnull)dictionary tableName:(NSString * _Nullable)tableName;
/**
  Return storaged language or default language in device

  returns:
  current used language
*/
- (NSString * _Nonnull)language;
/**
  Update default languaje, this store a language key and retrive the next time
*/
- (void)updateWithLanguage:(NSString * _Nonnull)string;
/**
  Update base file name, searched in path.
*/
- (void)updateWithFileName:(NSString * _Nonnull)fileName;
/**
  This remove the language key storaged.
*/
- (void)resetLanguage;
/**
  Show all aviable languajes whit criteria name

  returns:
  list with storaged languages code
*/
- (NSArray<NSString *> * _Nonnull)availableLanguages;
/**
  Display name for current user language.
  <ul>
    <li>
      return: String form language code in current user language
    </li>
  </ul>
*/
- (NSString * _Nonnull)displayNameForLanguage:(NSString * _Nonnull)language;
/**
  Enable testing mode
  Please not use in your code, is only for test schema.
*/
- (void)testingMode;
@end


@interface Localize (SWIFT_EXTENSION(Localize))
/**
  Localize a string using your JSON File
  If the key is not found return the same key
  That prevent replace untagged values

  returns:
  localized key or same text
*/
+ (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key tableName:(NSString * _Nullable)tableName;
/**
  Localize a string using your JSON File
  That replace all % character in your string with replace value.
  \param value The replacement value


  returns:
  localized key or same text
*/
+ (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key replace:(NSString * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
/**
  Localize a string using your JSON File
  That replace each % character in your string with each replace value.
  \param value The replacement values


  returns:
  localized key or same text
*/
+ (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key values:(NSArray * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
/**
  Localize string with dictionary values
  Get properties in your key with rule :property
  If property not exist in this string, not is used.
  \param value The replacement dictionary


  returns:
  localized key or same text
*/
+ (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key dictionary:(NSDictionary<NSString *, NSString *> * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
/**
  Return storaged language or default language in device

  returns:
  current used language
*/
+ (NSString * _Nonnull)language;
/**
  Update default languaje, this store a language key and retrive the next time
*/
+ (void)updateWithLanguage:(NSString * _Nonnull)string;
/**
  Update base file name, searched in path.
*/
+ (void)updateWithFileName:(NSString * _Nonnull)fileName;
/**
  This remove the language key storaged.
*/
+ (void)resetLanguage;
/**
  Show all aviable languajes whit criteria name

  returns:
  list with storaged languages code
*/
+ (NSArray<NSString *> * _Nonnull)availableLanguages;
/**
  Display name for current user language.
  <ul>
    <li>
      return: String form language code in current user language
    </li>
  </ul>
*/
+ (NSString * _Nonnull)displayNameForLanguage:(NSString * _Nonnull)language;
/**
  Enable testing mode
  Please not use in your code, is only for test schema.
*/
+ (void)testingMode;
@end

@class NSCoder;

/**
  Class to localize your ui elements
  use localizableKey matched in your file.
*/
SWIFT_CLASS("_TtC8Localize21LocalizeBarButtonItem")
@interface LocalizeBarButtonItem : UIBarButtonItem
/**
  Inspectable element to replace title in UIBarButtonItem.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKey;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


/**
  Class to localize your ui elements
  use localizableKey matched in your file.
*/
SWIFT_CLASS("_TtC8Localize15LocalizeBarItem")
@interface LocalizeBarItem : UITabBarItem
/**
  Inspectable element to replace title in UITabBarItem.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKey;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


/**
  Class to localize your ui elements
  use localizableKey matched in your file.
*/
SWIFT_CLASS("_TtC8Localize14LocalizeButton")
@interface LocalizeButton : UIButton
/**
  Inspectable element to replace title in UIButton.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKey;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSBundle;

SWIFT_CLASS("_TtC8Localize22LocalizeCommonProtocol")
@interface LocalizeCommonProtocol : NSObject
/**
  Name for storaged Json Files
  The rule for name is fileName-LanguageKey.json
*/
@property (nonatomic, copy) NSString * _Nonnull fileName;
/**
  Use this for testing mode, search resources in different bundles.
*/
@property (nonatomic) BOOL testing;
/**
  Path for your env
  if testing mode is enable we change the bundle
  in other case use a main bundle.

  returns:
  a string url where is your file
*/
- (NSBundle * _Nonnull)bundle;
/**
  Update default languaje, this store a language key and retrive the next time
*/
- (void)updateWithLanguage:(NSString * _Nonnull)string;
/**
  This remove the language key storaged.
*/
- (void)resetLanguage;
/**
  Display name for current user language.
  <ul>
    <li>
      return: String form language code in current user language
    </li>
  </ul>
*/
- (NSString * _Nonnull)displayNameForLanguage:(NSString * _Nonnull)language;
/**
  Enable testing mode
  Please not use in your code, is only for test schema.
*/
- (void)testingMode;
/**
  Return storaged language or default language in device

  returns:
  current used language
*/
- (NSString * _Nonnull)language;
/**
  Update base file name, searched in path.
*/
- (void)updateWithFileName:(NSString * _Nonnull)fileName;
/**
  Localize a string using your JSON File
  If the key is not found return the same key
  That prevent replace untagged values

  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key tableName:(NSString * _Nullable)tableName;
/**
  Localize a string using your JSON File
  That replace all % character in your string with replace value.
  \param value The replacement value


  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key replace:(NSString * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
/**
  Localize a string using your JSON File
  That replace each % character in your string with each replace value.
  \param value The replacement values


  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key values:(NSArray * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
/**
  Localize string with dictionary values
  Get properties in your key with rule :property
  If property not exist in this string, not is used.
  \param value The replacement dictionary


  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key dictionary:(NSDictionary<NSString *, NSString *> * _Nonnull)replace tableName:(NSString * _Nullable)tableName;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8Localize12LocalizeJson")
@interface LocalizeJson : LocalizeCommonProtocol
/**
  Create default lang name
*/
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
/**
  Localize a string using your JSON File
  If the key is not found return the same key
  That prevent replace untagged values

  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key tableName:(NSString * _Nullable)tableName;
/**
  Show all aviable languajes whit criteria name

  returns:
  list with storaged languages code
*/
- (NSArray<NSString *> * _Nonnull)availableLanguages;
@end


/**
  Class to localize your ui elements
  use localizableKey matched in your file.
*/
SWIFT_CLASS("_TtC8Localize13LocalizeLabel")
@interface LocalizeLabel : UILabel
/**
  Inspectable element to replace text in UILabel.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKey;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


/**
  Class to localize your ui elements
  use localizableKeyTitle and localizableKeyPrompt matched in your file.
*/
SWIFT_CLASS("_TtC8Localize25LocalizeNavigationBarItem")
@interface LocalizeNavigationBarItem : UINavigationItem
/**
  Inspectable element to replace title in UINavigationItem.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKeyTitle;
/**
  Inspectable element to replace prompt in UINavigationItem.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKeyPrompt;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)initWithTitle:(NSString * _Nonnull)title OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


/**
  Class to localize your ui elements
  use localizableKeyPlaceholder and localizableKeyPrompt matched in your file.
*/
SWIFT_CLASS("_TtC8Localize17LocalizeSearchBar")
@interface LocalizeSearchBar : UISearchBar
/**
  Inspectable element to replace placeholder in UISearchBar.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKeyPlaceholder;
/**
  Inspectable element to replace prompt in UISearchBar.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKeyPrompt;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


/**
  Class to localize your ui elements
  use localizableKey matched in your file.
*/
SWIFT_CLASS("_TtC8Localize26LocalizeSegmentedControler")
@interface LocalizeSegmentedControler : UISegmentedControl
/**
  Inspectable element to replace titles in UISegmentedControl.
  Please separete keys with ,
*/
@property (nonatomic, copy) NSString * _Nullable localizableKey;
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
- (nonnull instancetype)initWithItems:(NSArray * _Nullable)items OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8Localize15LocalizeStrings")
@interface LocalizeStrings : LocalizeCommonProtocol
/**
  Create default lang name
*/
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
/**
  Localize a string using your JSON File
  If the key is not found return the same key
  That prevent replace untagged values

  returns:
  localized key or same text
*/
- (NSString * _Nonnull)localizeWithKey:(NSString * _Nonnull)key tableName:(NSString * _Nullable)tableName;
/**
  Show all aviable languajes whit criteria name

  returns:
  list with storaged languages code
*/
- (NSArray<NSString *> * _Nonnull)availableLanguages;
@end


/**
  Class to localize your ui elements
  use localizableKeyText and localizableKeyPlaceholder matched in your file.
*/
SWIFT_CLASS("_TtC8Localize17LocalizeTextField")
@interface LocalizeTextField : UITextField
/**
  Inspectable element to replace text in UITextField.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKeyText;
/**
  Inspectable element to replace placeholder in UITextField.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKeyPlaceholder;
- (void)awakeFromNib;
- (void)localize;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSTextContainer;

/**
  Class to localize your ui elements
  use localizableKey matched in your file.
*/
SWIFT_CLASS("_TtC8Localize16LocalizeTextView")
@interface LocalizeTextView : UITextView
/**
  Inspectable element to replace text in UITextView.
*/
@property (nonatomic, copy) NSString * _Nullable localizableKey;
- (void)awakeFromNib;
- (void)localize;
- (nonnull instancetype)initWithFrame:(CGRect)frame textContainer:(NSTextContainer * _Nullable)textContainer OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


@interface UIBarButtonItem (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTag;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title for UIBarButtonItem
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
@end


@interface UIButton (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTag;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title for UIButton in each state
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
@end


@interface UILabel (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTag;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title for UILabel
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
@end


@interface UINavigationItem (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTagTitle;
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTagPrompt;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title and prompt for UINavigationItem
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
/**
  Here we change text with key replacement for title
*/
- (void)localizeTitle;
/**
  Here we change text with key replacement for prompt
*/
- (void)localizePrompt;
@end


@interface UISearchBar (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTagPlaceholder;
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTagPrompt;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title and prompt for UISearchBar
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
/**
  Here we change text with key replacement for placeholder
*/
- (void)localizePlaceholder;
/**
  Here we change text with key replacement for prompt
*/
- (void)localizePrompt;
@end


@interface UISegmentedControl (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTag;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title for UISegmentedControl in each state
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
@end


@interface UITabBarItem (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTag;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title for UITabBarItem
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
@end


@interface UITextField (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTagText;
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTagPlaceholder;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title and placeholder for UITextField
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
/**
  Here we change text with key replacement for placeholder
*/
- (void)localizePlaceholder;
/**
  Here we change text with key replacement for text
*/
- (void)localizeText;
@end


@interface UITextView (SWIFT_EXTENSION(Localize))
/**
  Localizable tag storeged property
*/
@property (nonatomic, copy) NSString * _Null_unspecified localizeTag;
/**
  Override awakeFromNib when is going visible, try search a key in JSON File
  If key match replace text, if can’t match return the key (original text)
  Set title for UITextView
*/
- (void)awakeFromNib;
/**
  Here we change text with key replacement
*/
- (void)localize;
@end

#pragma clang diagnostic pop
