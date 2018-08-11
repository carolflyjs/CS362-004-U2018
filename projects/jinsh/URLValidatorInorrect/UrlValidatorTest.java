import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

// Partition source: https://en.wikipedia.org/wiki/URL


public class UrlValidatorTest extends TestCase {
    public UrlValidatorTest(String testName) {
        super(testName);
    }


    /*
    * Testing: Manual tests
    *
    */

    /*
    *  Bug scenarios
    *  	-> h3t / https (regex error)
    *   -> http:/ (passing but should fail)
    *   -> /test1/ (failing but should be true)
    *   -> www.google (true but should be false)
    *   -> www.google.com//  (passing, but should fail)
    */

    public void testManualTest()
    {
        System.out.println("-----Manual Tests -----");
        int PASS = 0, FAIL = 0;
        UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

        String tureManualTest[] = {
            "http://www.google.com",
            "http://www.google.com:80/test/index.html/",
            "http://google.com",
            "http://google.com/facebook"
        };

        String falseManualTest[] = {
            "http://www.com",
            "http:/google.com",
            "httwwgoocom",
            "12315",
            "http://google.com///test1",
            "C:/Programs/index.html",
            "www3.google.com"
        };


        for(int i = 0; i < tureManualTest.length; i++) {
            System.out.printf("\"%s\" -- Result: ", tureManualTest[i]);
            if (urlVal.isValid(tureManualTest[i])) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        for(int i = 0; i < falseManualTest.length; i++) {
            System.out.printf("\"%s\" -- Result: ", falseManualTest[i]);
            if (!urlVal.isValid(falseManualTest[i])) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        System.out.printf("%n------Manual Tests Complete------%n");
        System.out.printf("      PASS: %d, FAIL: %d%n%n", PASS, FAIL);
        System.out.flush();
    }

    public void testYourFirstPartition()
    {
        System.out.println();
        System.out.println("-----First Parition: Authority-----");
        int PASS = 0, FAIL = 0;
        UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

        String trueAuth[] = {
        	"255.255.255.255",
            "google.com",
            "google..",
            "google.com/",
            "google.com",
            "www.google.com"
        };
        String falseAuth[] = {
            "google",
            "80",
            "400.400.400.400",
            "google..",
            "google.com//",
            "google.com/..facebook"

        };
        for(int i = 0; i < trueAuth.length; i++) {
            System.out.printf("\"%s\" -- Result: ", trueAuth[i]);
            if (urlVal.isValid("http://" + trueAuth[i])){
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        for(int i = 0; i < falseAuth.length; i++) {
            System.out.printf("\"%s\" -- Result: ", falseAuth[i]);
            if (urlVal.isValid("http://" + falseAuth[i])){
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        System.out.printf("%n------First Partition Complete------%n");
        System.out.printf("      PASS: %d, FAIL: %d%n%n", PASS, FAIL);
        System.out.flush();
    }

    public void testYourSecondPartition(){
        int PASS = 0, FAIL = 0;
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        System.out.println();
        System.out.println("-----Second Partition: Schemes-----");

        String[] trueSchemes = {
        	"http://",
            ""};

        String[] falseSchemes = {
        	"3htp://",
            "http//",
            "http:/",
            "http:",
            "://"};

        String otherParts = "www.google.com";

        //test isValid() with supposedly valid URL's
        String testString;
        for (int i = 0; i < trueSchemes.length; i++) {
            testString = trueSchemes[i] + otherParts;
            System.out.printf("\"%s\" -- Result: ", testString);
            if (urlVal.isValid(testString)) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        for (int i = 0; i < falseSchemes.length; i++) {
            testString = falseSchemes[i] + otherParts;
            System.out.printf("\"%s\" -- Result: ", testString);
            if (!urlVal.isValid(testString)) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        System.out.printf("%n------Second Partition Complete------%n");
        System.out.printf("      PASS: %d, FAIL: %d%n%n", PASS, FAIL);
        System.out.flush();

    }

    /*
    *
    */
    public void testYourThirdPartition(){
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        System.out.println();
        System.out.println("-----Third Partition: Path-----");

        int PASS = 0, FAIL = 0;
        String testString;
        String prefix = "http://www.google.com";

        String[] truePath = {
        	"",
            "/test1",
            "/test1/",
            "/t123",
            "/123",
            "/$23"};

        String[] falsePath = {
        	"/..",
            "/../",
            "//.",
            "//.//",
            "/test1//file",
            "//test/file"};
        //test isValid() with supposedly valid URL's
        for (int i = 0; i < truePath.length; i++) {
            testString = prefix + truePath[i];
            System.out.printf("\"%s\" -- Result: ", testString);
            if (urlVal.isValid(testString)) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        for (int i = 0; i < falsePath.length; i++) {
            testString = prefix + falsePath[i];
            System.out.printf("\"%s\" -- Result: ", testString);
            if (!urlVal.isValid(testString)) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        System.out.printf("%n------Third Partition Complete------%n");
        System.out.printf("      PASS: %d, FAIL: %d%n%n", PASS, FAIL);
    }

    public void testYourFourthPartition(){
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        System.out.println();
        System.out.println("-----Fourth Partition: Query-----");

        int PASS = 0, FAIL = 0;
        String testString;
        String prefix = "http://www.google.com/";

        String[] trueQuery = {
        	"",
            "?action=edit",
            "?action=edit&mode=up",
            "?action=edit&ampmode=up"};

        String[] falseQuery = {
        	"@action=edit",
            "!action=edit",
            "&action=edit"};

        //test isValid() with supposedly valid URL's
        for (int i = 0; i < trueQuery.length; i++) {
            testString = prefix + trueQuery[i];
            System.out.printf("\"%s\" -- Result: ", testString);
            if (urlVal.isValid(testString)) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        for (int i = 0; i < falseQuery.length; i++) {
            testString = prefix + falseQuery[i];
            System.out.printf("\"%s\" -- Result: ", testString);
            if (!urlVal.isValid(testString)) {
                System.out.println("PASS");
                PASS++;
            } else {
                System.out.println("FAIL");
                FAIL++;
            }
        }
        System.out.printf("%n------Fourth Partition Complete------%n");
        System.out.printf("      PASS: %d, FAIL: %d%n%n", PASS, FAIL);
    }

    public void testIsValid()
    {
        UrlValidator urlTest = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
    	System.out.println();
        System.out.println("-----Programming Based Test-----");

        int PASS = 0, FAIL = 0;

        String auth[] = {
        	"255.255.255.255",
            "google.com",
            "google..",
            "google.com/",
            "google.com",
            "www.google.com",
            "google",
            "80",
            "400.400.400.400",
            "google..",
            "google.com//",
            "google.com/..facebook"
        };

        boolean authExpect[] = {
        	true,
        	true,
        	true,
        	true,
        	true,
        	true,
        	false,
        	false,
        	false,
        	false,
        	false,
        	false
        };

        String[] scheme = {
        	"http://",
            "",
        	"3htp://",
            "http//",
            "http:/",
            "http:",
            "://"
        };

        boolean schemeExpect[] = {
        	true,
        	true,
        	false,
        	false,
        	false,
        	false,
        	false
        };

        String[] path = {
        	"",
            "/test1",
            "/test1/",
            "/t123",
            "/123",
            "/$23",
        	"/..",
            "/../",
            "//.",
            "//.//",
            "/test1//file",
            "//test/file"
        };

        boolean pathExpect[] = {
    		true,
        	true,
        	true,
        	true,
        	true,
        	true,
        	false,
        	false,
        	false,
        	false,
        	false,
        	false
        };

        String[] query = {
        	"",
            "?action=edit",
            "?action=edit&mode=up",
            "?action=edit&ampmode=up",
        	"@action=edit",
            "!action=edit",
            "&action=edit"};

        boolean[] queryExpect = {
        	true,
        	true,
        	true,
        	true,
        	false,
        	false,
        	false
        };

        for (int i = 0; i < scheme.length; i++) {
            for (int j = 0; j < auth.length; j++) {
            	for (int m = 0; m < path.length; m++) {
            		for (int n = 0; n < query.length; n++) {
            			String testString = scheme[i] + auth[j] + path[m] + query[n];
            			boolean expected = schemeExpect[i] && authExpect[j] && pathExpect[m] && queryExpect[n];
            			System.out.printf("\"%s\" -- Result: ",  testString);
                        if (urlTest.isValid(testString) == expected) {
                            System.out.print("Pass\n");
                            PASS++;
                        }
                        else {
                            System.out.print("Fail\n");
                            FAIL++;
                        }
            		}
            	}
            }
        }

        System.out.printf("%n------Programming Based Test Complete------%n");
        System.out.printf("      PASS: %d, FAIL: %d%n%n", PASS, FAIL);
    }
}
